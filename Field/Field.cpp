#include "Field.hpp"
#include <vector>
#include <random>

Field::Field(){
    this->previousFrameTime = getMainTime();
    this->currentFrameTime = getMainTime();
    this->fieldWidth = 1200;
    this->fieldHeight = 1200;
}

Field::~Field(){
    animalArr.clear();
}

//possible type inputs: Boar, Cow, Fox, Goose, Gorilla, Pig, Sheep, Wolf
void Field::spawnAnimal(string animalType, sf::Vector2f pos){
    Animals *animal;
    if (animalType == "Wolf"){ 
        animal = new Wolf;
        animalArr.push_back(animal);
    }
    else if (animalType == "Sheep"){ 
        animal = new Sheep;
        animalArr.push_back(animal);
    }
    else if (animalType == "Pig"){ 
        animal = new Pig;
        animalArr.push_back(animal);
    }
    else if (animalType == "Gorilla"){ 
        animal = new Gorilla;
        animalArr.push_back(animal);
    }
    else if (animalType == "Goose"){ 
        animal = new Goose;
        animalArr.push_back(animal);
    }
    else if (animalType == "Fox"){ 
        animal = new Fox;
        animalArr.push_back(animal);
    }
    else if (animalType == "Cow"){ 
        animal = new Cow;
        animalArr.push_back(animal);
    }
    else if (animalType == "Boar"){ 
        animal = new Boar;
        animalArr.push_back(animal);
    }
    else{
        throw std::invalid_argument( "recieved invalid type argument" );
    }
    animal->setCoords(pos.x, pos.y);
}
void Field::spawnAnimal(string animalType){
    std::random_device rd;   // non-deterministic generator
    std::mt19937 gen(rd());  // to seed mersenne twister.
    std::uniform_int_distribution<> distX(10, this->fieldWidth - 10);
    int xCoord = distX(gen);
    std::uniform_int_distribution<> distY(10, this->fieldHeight - 10);
    int yCoord = distY(gen);
    this->spawnAnimal(animalType, sf::Vector2f(xCoord, yCoord));
}

//as seconds
float Field::getMainTime(){
    return this->mainClock.getElapsedTime().asSeconds();
}

void Field::update(){
    for (int i = 0; i < this->animalArr.size(); i++){
        if (animalArr[i]->alive){
        animalArr[i]->move(animalArr[i]->aiDirection(&(this->animalArr), true), this->currentFrameTime - this->previousFrameTime);
        animalArr[i]->foodCheck(&(this->animalArr));
        }
    }
    checkForBounds();
    this->previousFrameTime = this->currentFrameTime;
    this->currentFrameTime = getMainTime();
}

std::vector<Animals*> Field::getAnimalArr(){
    return this->animalArr;
};

void Field::checkForBounds(){
    for (int i = 0; i < this->animalArr.size(); i++){
        if (this->animalArr[i]->position.x > this->fieldWidth){
            this->animalArr[i]->setCoords(this->fieldWidth, this->animalArr[i]->position.y);
        }
        if (this->animalArr[i]->position.x < 0){
            this->animalArr[i]->setCoords(0, this->animalArr[i]->position.y);
        }
        if (this->animalArr[i]->position.y > this->fieldHeight){
            this->animalArr[i]->setCoords(this->animalArr[i]->position.x, this->fieldHeight);
        }
        if (this->animalArr[i]->position.y < 0){
            this->animalArr[i]->setCoords(this->animalArr[i]->position.x, 0);
        }
    }
};
