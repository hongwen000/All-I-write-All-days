#include "Solution.h"
#include <vector>
#include <iostream>
using namespace std;
bool bs(const vector<int>& A, int target)
{
    int lo = 0;
    int hi = A.size();
    while(lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        if(A[mid] == target)
        {
            return true;
        }
        else if (A[mid] < target)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }    
    return false;
}

bool Solution::searchMatrix(vector<vector<int> >& matrix, int target) {
    for(unsigned i = 0; i < matrix.size(); ++i)
    {
        vector<int>& v = matrix[i];
        if(v.empty()) continue;
        if(v[v.size() - 1] < target || v[0] > target) continue;
        if(bs(v, target))
            return true;
    }
    return false;
}

