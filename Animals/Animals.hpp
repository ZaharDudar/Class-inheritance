#pragma once
#include <string>
#include <iostream>
#include "Food.hpp"
#include <string>
#include <chrono>
#include "SFML/System/Vector2.hpp"

using namespace std;

class Animals
{
protected:
    int legs;
    sf::Vector2f position;
public:
    int animFrame=0;
    int64_t lastAnimUpdate;
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


