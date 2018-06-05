#ifndef H_ANIMAL_H
#define H_ANIMAL_H
#include <iostream>
#include <string>
using namespace std;

enum Type {
    CAT,
    DOG
};

class Animal {
public:
    Animal(){}
    Animal(std::string _name, int _age)
        : name(_name)
        , age(_age)
    {
    }
    virtual ~Animal() {}
    virtual void Shout() const = 0;
    virtual Type getType() const = 0;
    std::string getName() const
    {
        return name;
    }

    int getAge() const
    {
        return age;
    }

private:
    std::string name;
    int age;
};

class Cat : public Animal {
public:
    Cat() {}
    Cat(std::string _name, int _age)
        : Animal(_name, _age)
    {
    }
    void Shout() const override {
        cout << ": meow~~" << endl;
    }
    Type getType() const override {
        return CAT;
    }
};

class Dog : public Animal {
public:
    Dog(){}
    Dog(std::string _name, int _age)
        : Animal(_name, _age)
    {
    }
    void Shout() const override {
        cout << ": bark!!" << endl;
    }
    Type getType() const override {
        return DOG;
    }
};
#endif
