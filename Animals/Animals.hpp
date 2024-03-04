#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Food.hpp"
#include <string>
#include <chrono>
#include <cmath>
#include "SFML/System/Vector2.hpp"

using namespace std;

// enum AnimalTypes{
// Boar,
// Cow,
// Fox,
// Goose,
// Gorilla,
// Pig,
// Sheep,
// Wolf
// };

class Animals
{
protected:
    int legs;
    std::vector<string> attractors;
    std::vector<string> repulsors;
    std::vector<string> food; // eats this sht, not eaten by it
    float moveSpeed;
    string typeName;
public:
    bool forcedReturn; // shit for collision
    sf::Vector2f position; //------change back to protected
    int animFrame=0;
    int64_t lastAnimUpdate;
    string sprite;
    float collisionRadius, viewRarius;
    bool lookDirection; //false for left, true for right
    sf::Vector2f aiDirection(std::vector<Animals*>*, bool);
    float getSqrDistanceTo(Animals*);
    bool circleCollision(Animals*);
    void setCoords(float, float);
    void move(sf::Vector2f, float);
    virtual void say() = 0;
    //deletes every food in 2.5 radius of collisionRadius
    void foodCheck(std::vector<Animals*>*);
    float getCollisionRadius();
    bool alive;
    Animals();
    ~Animals(){};
};

class Herbivores : public Animals {
};

class Predators : public Animals {
};


