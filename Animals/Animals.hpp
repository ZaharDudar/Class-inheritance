#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Food.hpp"
#include <string>
#include <chrono>
#include <cmath>
#include "SFML/System/Vector2.hpp"
#include <SFML/Graphics.hpp>

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
    sf::Vector2f prev_position;
    bool needs_food;
    float food_max;  // max pseudotimer value for starving
    float reproduction_max;  // max pseudotimer value for wee wee sexo sexo
    // ⠀⠀⠀⠀⠀⠀⠀⣴⣶⣦⣤⣴⣶⣶⣿⣿⣿⣿⣷⣶⣦⣤⣄⣀⡀⠀⠀⠀⣀⡀
    // ⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⡋⠀⠀
    // ⠀⠀⣠⣤⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠀⠀
    // ⠙⠟⠛⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀
    // ⠀⠀⠀⠻⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡀
    // ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢡⣶⡿⢿⡿⠿⠿⠂⠀⠉⠉⠉⠀⣀⣿⡿⠟⠛⠿⣿⣷⡀
    // ⠀⠀⠀⠀⠀⠀⠀⢀⣰⠟⠀⠀⠈⠛⠳⠀⠀⠀⠀⠀⢠⡾⠋⠀⠀⠀    ⠈⠛⠳s
    int idle_sec_count;
    int idle_change_time; // every *this* seconds change idle wander direction
    sf::Vector2f idle_direction;
    bool has_eaten; // if hasn't eaten no children
public:
    float random_seed; // shit for pseudo-random wander, set to index in animallArr via spawn method from Field
    float food_clock;  // pseudotimer for starving to death
    float reproduct_clock;  // pseudotimer for wee wee sexo sexo
    bool forcedReturn; // shit for collision
    sf::Vector2f position; //------change back to protected -- maybe sometime later :/
    int animFrame=0;
    int64_t lastAnimUpdate;
    string sprite;
    float collisionRadius, viewRarius;
    bool lookDirection; //false for left, true for right
    sf::Vector2f aiDirection(std::vector<Animals*>*, bool, float);
    float getSqrDistanceTo(Animals*);
    bool circleCollision(Animals*);
    void setCoords(float, float);
    void move(sf::Vector2f, float, float);
    virtual void say() = 0;
    //deletes every food in 2.5 radius of collisionRadius
    bool foodCheck(std::vector<Animals*>*, float);
    float getCollisionRadius();
    string getTypeName();
    bool alive;
    float deathAnimationPercent; //factor of animation death where 100 - idle, 0 - dead
    Animals();
    ~Animals(){};
};

class Herbivores : public Animals {
};

class Predators : public Animals {
};