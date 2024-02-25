#pragma once
#include "Animals/Animals.hpp"
#include "Animals/Wolf.hpp"
#include "string"
#include <SFML/Graphics.hpp>


class Field
{
protected:
    int fieldHeight;
    int fieldWidth;
    float previousFrameTime, currentFrameTime;

    sf::Clock mainClock;

    std::vector<Animals*> animalArr;

public:
    void spawnAnimal(string);
    float getMainTime();
    void update();
};
