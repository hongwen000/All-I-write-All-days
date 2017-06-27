
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
template <class T>
class Queue {
  public:
    Queue(){
    	node_num=0;
    	front_node=NULL;
    	back_node=NULL;
	}
    Queue(const Queue & x){
    	front_node=new Node(x.front_node->element);
    	Node * n=front_node;
    	Node * t= x.front_node->next;
    	while(t!=NULL){
    		Node *nn= new Node(t->element);
    		n->next=nn;
    		n=n->next;
    		t=t->next;
		}
		back_node=n;
		node_num=x.node_num;
//		cout<<111<<endl;system("pause");
	}
    ~Queue(){
    	while(!empty())pop();
    	delete front_node;
    	delete back_node;
    	node_num=0;
	}
    bool empty(){
    	return node_num==0;
	}
    int size(){
    	return node_num;
	}
    T front() const{
		return front_node->element;
	}
    T back() const{
		return back_node->element;
	}
    void push(T ele){
    	Node * n=new Node(ele);
		node_num++;
		if(back_node==NULL){
    		back_node=n;
    		front_node=n;
    		return;
		}
    	back_node->next=n;
    	back_node=n;
	}
    void pop(){
    	Node * n=front_node;
    	front_node=front_node->next;
    	delete n;
	}
    void swap(Queue & q){
    	Node * t=q.front_node;
    	q.front_node=front_node;
    	front_node=t;
    	t=q.back_node;
    	q.back_node=back_node;
    	back_node=t;
    	int tt=q.node_num;
    	q.node_num=node_num;
    	node_num=tt;
	}

  private:
    struct Node {
      T element;
      Node* next;
      Node(T ele, Node* n = NULL) {
        element = ele;
        next = n;
      }
    };
    Node* front_node;
    Node* back_node;
    int node_num;
};


#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Job {
    public:
        explicit Job(int pri = 0) {
            id = number++;
            priority = pri;
        }
        string toString() {
            stringstream ss;
            ss << "[" << id << ":" << priority << "]";
            return ss.str();
        }
    private:
        static int number;
        int id;
        int priority;
};

int Job::number = 0;

template<class T>
void print(Queue<T> queue) {
	cout<<1<<endl;
	system("pasue");
    while (!queue.empty()) {
        cout << queue.front() << " ";
        queue.pop();
    }
    cout << endl;
}

int main() {
    // test case 1: integer..
    Queue<int> que;
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++) que.push(i + 0.01);
    print(que);
    //system("pause");
    for (int i = 0; i < n; i++) que.pop();
    print(que);
    //system("pause");
    if (!que.empty()) {
        cout << que.front() << endl;
        cout << que.back() << endl;
    }
    cout << "The size is: " << que.size() << endl;
    if (que.empty()) cout << "The queue is empty!" << endl;
    else cout << "The queue is NOT empty!" << endl;

    // test case 2: double..
    Queue<double> que1;
    cin >> m >> n;
    for (int i = 0; i < m; i++) que1.push(i + 0.01);
    for (int i = 0; i < n; i++) que1.pop();
    if (!que1.empty()) {
        cout << que1.front() << endl;
        cout << que1.back() << endl;
    }
    cout << "The size is: " << que1.size() << endl;
    if (que1.empty()) cout << "The queue is empty!" << endl;
    else cout << "The queue is NOT empty!" << endl;

    // test case 3: user defined class..
    Queue<Job> que2;
    cin >> m >> n;
    for (int i = 0; i < m; i++) que2.push(Job(i));
    for (int i = 0; i < n; i++) que2.pop();

    if (!que2.empty()) {
        cout << que2.front().toString() << endl;
        cout << que2.back().toString() << endl;
    }
    cout << "The size is: " << que2.size() << endl;
    if (que2.empty()) cout << "The queue is empty!" << endl;
    else cout << "The queue is NOT empty!" << endl;

    // test case 4: swap function..
    Queue<int> que3, que4;
    for (int i = 0; i < m; i++) que3.push(i);
    for (int i = 0; i < n; i++) que4.push(m - i);
    cout << "Before Swap...." << endl;
    print(que3);
    print(que4);

    que3.swap(que4);
    cout << "After Swap...." << endl;
    cout << endl;
    print(que3);
    print(que4);
}

