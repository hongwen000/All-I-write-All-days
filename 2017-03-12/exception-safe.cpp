#include <atomic>
#include <iostream>
#include <memory>
#include <pthread.h>
using std::atomic;
using myMutex_t = pthread_mutex_t;

class Image {
public:
    Image(std::istream&) {}
};

class myMutex;

class Lock {
public:
    explicit Lock(myMutex* pm)
        : mutexPtr(pm)
    {
        lock(mutexPtr);
    }
    ~Lock() { unlock(mutexPtr); }
    Lock(const Lock&) = delete;
    Lock& operator=(const Lock&) = delete;
    int lock(myMutex* pMutex);
    int unlock(myMutex* pMutex);

private:
    myMutex* mutexPtr;
};

myMutex_t* creat_myMutex_t(const pthread_mutexattr_t* mutexattr = NULL)
{
    myMutex_t* mymutex_raw = new pthread_mutex_t;
    pthread_mutex_init(mymutex_raw, mutexattr);
    return mymutex_raw;
}

class myMutex {
    friend int Lock::lock(myMutex* pMutex);
    friend int Lock::unlock(myMutex* pMutex);

public:
    explicit myMutex(const pthread_mutexattr_t* mutexattr = NULL) noexcept
        : mymutex(creat_myMutex_t(mutexattr))
    {
    }
    myMutex(const myMutex&) = delete;
    myMutex& operator=(const myMutex&) = delete;
    ~myMutex()
    {
        pthread_mutex_destroy(mymutex.get());
    }

private:
    std::unique_ptr<myMutex_t> mymutex;
};

int Lock::lock(myMutex* pMutex)
{
    return pthread_mutex_lock((pMutex->mymutex).get());
}

int Lock::unlock(myMutex* pMutex)
{
    return pthread_mutex_unlock((pMutex->mymutex).get());
}

struct PMImpl {
    std::shared_ptr<Image> bgImage;
    int imageChanges;
};

class PrettyMenu {
public:
    void changeBackground(std::istream& imgSrc);

private:
    myMutex mymutex;
    std::shared_ptr<PMImpl> pImpl;
};

void PrettyMenu::changeBackground(std::istream& imgSrc)
{
    using std::swap;
    Lock ml(&mymutex);
    std::shared_ptr<PMImpl>
        pNew(new PMImpl(*pImpl));
    pNew->bgImage.reset(new Image(imgSrc));
    ++pNew->imageChanges;
    swap(pImpl, pNew);
}

int main()
{
    return 0;
}
