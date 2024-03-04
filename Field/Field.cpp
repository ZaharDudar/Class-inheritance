#include "Field.hpp"
#include <vector>
#include <random>

Field::Field(){
    this->previousFrameTime = getMainTime();
    this->currentFrameTime = getMainTime();
    this->fieldWidth = 1200;
    this->fieldHeight = 900;
}

Field::~Field(){
    animalArr.clear();
}

//possible type inputs: Boar, Cow, Fox, Goose, Gorilla, Pig, Sheep, Wolf
void Field::spawnAnimal(string animalType, sf::Vector2f pos){
    Animals *animal;
    if (animalType == "Wolf"){ //-------------------------------------когда вмёржим в мейн въебать ещё ифов
        animal = new Wolf;
        animalArr.push_back(animal);
    }else{
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
        animalArr[i]->move(animalArr[i]->aiDirection(&(this->animalArr), true), this->currentFrameTime - this->previousFrameTime);
    }
    this->previousFrameTime = this->currentFrameTime;
    this->currentFrameTime = getMainTime();
}

std::vector<Animals*> Field::getAnimalArr(){
    return this->animalArr;
};
