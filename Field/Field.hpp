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
#include "../Animals/Bush.hpp"
#include <random>

class Field
{
protected:
    float previousFrameTime, currentFrameTime;
    sf::Clock mainClock;
    std::vector<Animals*> animalArr;
    float last_bush_spawned_time, bush_spawn_cd;

public:
    int fieldHeight;
    int fieldWidth;
    Field();
    ~Field();
    template<typename T>
    void spawnAnimal();
    template<typename T>
    void spawnAnimal(sf::Vector2f);
    float getMainTime();
    void update();
    std::vector<Animals*> getAnimalArr();
    void checkForBounds(); //sets all animals' coords to inside of bouds
};
//possible type inputs: Boar, Cow, Fox, Goose, Gorilla, Pig, Sheep, Wolf
template<typename T>
void Field::spawnAnimal(sf::Vector2f pos){
    Animals *animal;
    int arrIndex = -1;
    T tmp;
    if(dynamic_cast<Animals*>(&tmp)){
        for (int i = 0; i < animalArr.size(); i++){
            if ((animalArr[i]->alive == false) && (typeid(*animalArr[i]) == typeid(T))){
                arrIndex = i;
                break;
            }
        }
        if (arrIndex != -1){
            animalArr[arrIndex]->alive = true;
            animal = animalArr[arrIndex];
        }else{
            animal = new T;
            animalArr.push_back(animal);
        }
    }
    else{
        throw std::invalid_argument( "recieved invalid type argument" );
    }
    animal->setCoords(pos.x, pos.y);
    animal->food_clock.restart();
    animal->reproduct_clock.restart();
}
template<typename T>
void Field::spawnAnimal(){
    std::random_device rd;   // non-deterministic generator
    std::mt19937 gen(rd());  // to seed mersenne twister.
    std::uniform_int_distribution<> distX(10, this->fieldWidth - 10);
    int xCoord = distX(gen);
    std::uniform_int_distribution<> distY(10, this->fieldHeight - 10);
    int yCoord = distY(gen);
    this->spawnAnimal<T>(sf::Vector2f(xCoord, yCoord));
}