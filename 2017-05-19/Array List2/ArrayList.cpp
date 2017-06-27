#include "ArrayList.hpp"
ArrayList::ArrayList() : storage(NULL), _size(0), _maxsize(0)
{

}

ArrayList::~ArrayList()
{
    delete storage;
}

void ArrayList::add(E e)
{
    if(_size == _maxsize)
        extend();
    storage[_size] = e;
    ++_size;
}

void ArrayList::remove(E e)
{
    for(int i =0; i < _size; ++i)
    {
        if(e == storage[i])
        {
            if(i == _size)
                --_size;
            else
            {
                for(int j = i; j < _size; ++j)
                    storage[j] = storage[j + 1];
            }
        }
    }
}

void ArrayList::clear()
{
    _size = 0;
}

bool ArrayList::contain(E e)
{
    for(int i = 0; i < _size; ++i)
        if(storage[i] == e)
            return true;
    return false;
}

bool ArrayList::isEmpty()
{
    return (_size == 0);
}

E& ArrayList::operator[](int index)
{
    return storage[index];
}

E& ArrayList::get(int index)
{
    return storage[index];
}

int ArrayList::indexOf(E element)
{
        for(int i = 0; i < _size; ++i)
        if(storage[i] == element)
            return i;
    return -1;
}

int ArrayList::size()
{
    return _size;
}

void ArrayList::extend()
{
     E* newStorage = new E[_maxsize * extend_factor];
     for(int i = 0; i < _size; ++i)
        newStorage[i] = storage[i];
     delete storage;
     storage = newStorage;
}
