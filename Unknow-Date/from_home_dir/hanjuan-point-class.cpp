#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
class Point {
private:
    int* data;
    int dimension;

public:
    Point(int x)
    {
        try {
        dimension = x;
        data = new int[100];
        memset(data, 0, 100);
        }   catch(...)
        {
           cout << "aaaaa" << endl;
        } 
    }

    Point(int* x, int y)
    {
        try {
        data = new int[100];
        } catch (...) {
            cout << "hhh" << endl;
        }
        for (int i = 0; i < y; i++)
            data[i] = x[i];
        dimension = y;
    }
    Point operator+(const Point& x)
    {
        if (dimension > x.dimension) {
            Point y(dimension);
            y = *this;
            for (int i = 0; i < x.dimension; i++)
                y.data[i] += x.data[i];
            return y;
        } else {
            Point y(x.dimension);
            y = x;
            for (int i = 0; i < dimension; i++)
                y.data[i] += data[i];
            return y;
        }
    }
    Point operator-(const Point& x)
    {
        if (dimension > x.dimension) {
            Point y(dimension);
            y = *this;
            for (int i = 0; i < x.dimension; i++)
                y.data[i] -= x.data[i];
            return y;
        } else {
            Point y(x.dimension);
            for (int i = 0; i < x.dimension; i++) {
                if (i < dimension)
                    y.data[i] = data[i];
                else
                    y.data[i] = 0;
            }
            for (int i = 0; i < x.dimension; i++)
                y.data[i] -= x.data[i];
            return y;
        }
    }
   Point& operator=(const Point& rhs)
    {
        int realDim = min(dimension, rhs.dimension);
        int i = 0;
        
        for (i = 0; i < realDim; i++)
            data[i] = rhs.data[i];
        return *this;
    }

    void print()
    {
        cout << "(";
        if (dimension)
            cout << data[0];
        if (dimension >= 2)
            for (int i = 1; i < dimension; i++)
                cout << "," << data[i];
        cout << ")" << endl;
    }
    ~Point() 
    {
        delete [] data;
    }
};

