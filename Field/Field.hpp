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

class Field
{
protected:
    float previousFrameTime, currentFrameTime;
    sf::Clock mainClock;  //actually legacy at this point
    std::vector<Animals*> animalArr;  //array for all animals in da field
    float last_bush_spawned_time, bush_spawn_cd;
    float random_seed;  // for pseudo-random
public:
    float time_scale;
    int fieldHeight;
    int fieldWidth;
    Field();
    ~Field();
    void spawnAnimal(std::string name, int n, sf::Vector2f pos);
    template<typename T>
    void spawnAnimal();
    template<typename T>
    void spawnAnimal(sf::Vector2f);
    float getMainTime(); // legacy
    void update();  // main Field method
    std::vector<Animals*> getAnimalArr();
    void checkForBounds(); //sets all animals' coords to inside of bouds
};
//possible type inputs: Boar, Cow, Fox, Goose, Gorilla, Pig, Sheep, Wolf, Bush
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
            animal->random_seed = arrIndex;
        }else{
            animal = new T;
            animalArr.push_back(animal);
            animal->random_seed = animalArr.size();
        }
    }
    else{
        throw std::invalid_argument( "recieved invalid type argument" );
    }
    animal->setCoords(pos.x, pos.y);
    animal->food_clock = 0;
    animal->reproduct_clock = 0;
}
template<typename T>
void Field::spawnAnimal(){
    // std::random_device rd;   // non-deterministic generator
    // std::mt19937 gen(rd());  // to seed mersenne twister.
    // std::uniform_int_distribution<> distX(10, this->fieldWidth - 10);
    // int xCoord = distX(gen);

    int xCoord = ((this->random_seed+1)*0.31 - floor((this->random_seed+1)*0.31))*(this->fieldWidth - 20) + 10;
    // std::uniform_int_distribution<> distY(10, this->fieldHeight - 10);
    // int yCoord = distY(gen);
    int yCoord = (tan(this->random_seed+1) - floor(tan(this->random_seed+1)))*(this->fieldHeight - 20) + 10;
    this->random_seed++;
    this->spawnAnimal<T>(sf::Vector2f(xCoord, yCoord));
}

