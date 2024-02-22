#pragma once
#include <string>
#include <iostream>
#include "Food.hpp"
#include <string>
using namespace std;

class Animals
{
protected:
    int legs;
public:
    virtual void say() = 0;
    virtual bool canEat(Food *food) = 0;
    string sprite;
    ~Animals(){};
};
class Herbivores : public Animals {
public:
    bool canEat(Food *food){
        return !food->isMeat();
    }
};

class Predators : public Animals {
    public:
        bool canEat(Food *food){
            return food->isMeat(); 
        }
};


