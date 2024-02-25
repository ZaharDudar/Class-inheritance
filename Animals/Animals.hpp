#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Food.hpp"
#include "SFML/System/Vector2.hpp"

using namespace std;

class Animals
{
protected:
    sf::Vector2f position;
    float collisionRadius, viewRarius;
    bool lookDirection; //false for left, true for right
    float moveSpeed;
    string typeName;
public:
    // Animals *chase, *avoid;
    sf::Vector2f aiDirection(std::vector<Animals*>*, bool);
    float getSqrDistanceTo(Animals*);
    bool circleCollision(Animals*);
    void setCoords(int, int);
    void move(sf::Vector2f, float);
    virtual void say() = 0;
    virtual bool canEat(Food *food) = 0;
    float getCollisionRadius();
    ~Animals(){};
    std::vector<string> attractors;
    std::vector<string> repulsors;
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


