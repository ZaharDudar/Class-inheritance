#include "Field.hpp"
#include <vector>
#include <random>

Field::Field(){
    this->previousFrameTime = getMainTime();
    this->currentFrameTime = getMainTime();
}

Field::~Field(){
    animalArr.clear();
}

//possible type inputs: Boar, Cow, Fox, Goose, Gorilla, Pig, Sheep, Wolf
void Field::spawnAnimal(string animalType){
    Animals *animal;
    if (animalType == "Wolf"){ //-------------------------------------когда вмёржим в мейн въебать ещё ифов
        animal = new Wolf;
        animalArr.push_back(animal);
    }else{
        throw std::invalid_argument( "recieved invalid type argument" );
    }
    std::random_device rd;   // non-deterministic generator
    std::mt19937 gen(rd());  // to seed mersenne twister.
    std::uniform_int_distribution<> dist(animal->getCollisionRadius(), this->fieldWidth - animal->getCollisionRadius()); // distribute results between 1 and 6 inclusive.
    int xCoord = dist(gen);
    std::uniform_int_distribution<> dist(animal->getCollisionRadius(), this->fieldHeight - animal->getCollisionRadius()); // distribute results between 1 and 6 inclusive.
    int yCoord = dist(gen);
    animal->setCoords(xCoord, yCoord);
}

//as seconds
float Field::getMainTime(){
    return this->mainClock.getElapsedTime().asSeconds();
}

void Field::update(){
    for (int i = 0; i < this->animalArr.size(); i++){
        animalArr[i]->move(animalArr[i]->aiDirection(&(this->animalArr), true), this->currentFrameTime - this->previousFrameTime);
    }
    this->currentFrameTime = this->previousFrameTime;
    this->currentFrameTime = getMainTime();
}