#pragma once
#include "../Animals/Animals.hpp"
#include "../Animals/Wolf.hpp"
#include "string"
#include <SFML/Graphics.hpp>


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
    float getMainTime();
    void update();
    std::vector<Animals*> getAnimalArr();
};
