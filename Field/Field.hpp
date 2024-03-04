#pragma once
#include "../Animals/Animals.hpp"
#include "../Animals/Wolf.hpp"
#include "string"
#include <SFML/Graphics.hpp>
#include "../Animals/Sheep.hpp"
#include "../Animals/Pig.hpp"
#include "../Animals/Gorilla.hpp"
#include "../Animals/Goose.hpp"
#include "../Animals/Fox.hpp"
#include "../Animals/Cow.hpp"
#include "../Animals/Boar.hpp"

class Field
{
protected:
    float previousFrameTime, currentFrameTime;
    sf::Clock mainClock;
    std::vector<Animals*> animalArr;

public:
    int fieldHeight;
    int fieldWidth;
    Field();
    ~Field();
    void spawnAnimal(string);
    void spawnAnimal(string, sf::Vector2f);
    float getMainTime();
    void update();
    std::vector<Animals*> getAnimalArr();
    void checkForBounds(); //sets all animals' coords to inside of bouds
};
