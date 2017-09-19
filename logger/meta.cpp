#include "meta.h"
void base::print() const{
    for(auto& func : vecfunc)
        func();
}
