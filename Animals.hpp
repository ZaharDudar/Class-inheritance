#include <string>
#include <iostream>
#include "Food.hpp"

using namespace std;

class Animals
{
protected:
    int legs;
public:
    virtual void say() = 0;
    virtual bool canEat(Food *food) = 0;
    ~Animals(){};
};

class Predators : public Animals {
    public:
        bool canEat(Food *food){
            return food->isMeat(); 
        }
};


