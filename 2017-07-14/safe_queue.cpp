#include <thread>
#include <queue>
#include <memory>
#include <mutex>
#include <condition_variable>

using namespace std;

template <typename T>
class threadsafe_queue
{
private:
    mutable mutex mut;
    queue<T> data_queue;
    condition_variable data_cond;
public:
    threadsafe_queue()
    {}
    threadsafe_queue(threadsafe_queue const& other)
    {
        lock_guard<mutex> lk(other.mut);
        data_queue = other.data_queue;
    }
    void push(T new_value)
    {
        lock_guard<mutex> lk(mut);
        data_queue.push(new_value);
        data_cond.notify_one();
    }
    void wait_and_pop(T& value)
    {
        unique_lock<mutex> lk(mut);
        data_cond.wait(lk, [this](){return !data_queue.empty();});
        value = data_queue.front();
        data_queue.pop();
    }
    shared_ptr<T> wait_and_pop()
    {
        unique_lock<mutex> lk(mut);
        data_cond.wait(lk, [this](){return !data_queue.empty();});
        shared_ptr<T> res(make_shared<T>(data_queue.front()));
        data_queue.pop();
        return res;
    }
    bool try_pop(T& value)
    {
        lock_guard<mutex> lk(mut);
        if(data_queue.empty())
            return false;
        value = data_queue.front;
        data_queue.pop();
        return true;
    }
    shared_ptr<T> try_pop()
    {
        lock_guard<mutex> lk(mut);
        if(data_queue.empty())
            return shared_ptr<T>();
        shared_ptr<T> res(make_shared<T>(data_queue.front()));
        data_queue.pop();
        return res;
    }
    bool empty() const
    {
        lock_guard<mutex> lk(mut);
        return data_queue.empty();
    }
};

static threadsafe_queue<int> que;
void fun_push()
{
    for(int i = 0; i < 10; ++i)
    {
       que.push(i); 
    }
}
void fun_front()
{
    for(int i = 0; i < 10; ++i)
    {
        auto p = que.wait_and_pop();
        // auto p = que.try_pop(); //结果是有时有输出，有时没有
        if(p)
            printf("%d\n", *p);
    }
}
#include <iostream>
int main()
{
    thread t1(fun_push);
    thread t2(fun_front);
    t1.join();
    t2.join();
}