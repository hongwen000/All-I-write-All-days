#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> set;

set setIntersection(const set A, const set B)

{
     std::vector<int> v_intersection;

    std::set_intersection(A.begin(), A.end(),
                          B.begin(), B.end(),
                          std::back_inserter(v_intersection));
    return v_intersection;
}


