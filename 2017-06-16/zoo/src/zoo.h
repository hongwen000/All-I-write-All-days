#include <vector>
#include "animal.h"
#include <map>
using namespace std;
class Zoo {
public:
    void addAnimal(Animal* ani) {
        for(auto i : animals) {
            if(i == ani)
                return;
        }
        animals.push_back(ani);
    }

    int getCatCount() {
        int ret{};
        for(auto i : animals) {
            if(i->getType() == CAT)
                ret++;
        }
        return ret;
    }

    int getDogCount() {
        int ret{};
        for(auto i : animals) {
            if(i->getType() == DOG)
                ret++;
        }
        return ret;
    }

    void deleteAnimalByName(string _name) {
        for(auto i = animals.begin(); i != animals.end();)
            if((*i)->getName() == _name)
                i = animals.erase(i);
            else
                ++i;
    }

    void deleteAnimalByAge(int _age) {
        for(auto i = animals.begin(); i != animals.end();)
            if((*i)->getAge() == _age)
                i =  animals.erase(i);
            else
                ++i;
    }

    void print() {
        for(auto i : animals) {
            cout << i->getName();
            i->Shout();
        }
    }
private:
    vector<Animal*> animals;
};
