#include "Field.hpp"
#include <vector>
#include <random>

Field::Field(){
    this->previousFrameTime = getMainTime();
    this->currentFrameTime = getMainTime();
    this->fieldWidth = 500;
    this->fieldHeight = 500;
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
    std::uniform_int_distribution<> distX(animal->getCollisionRadius(), this->fieldWidth - animal->getCollisionRadius());
    int xCoord = distX(gen);
    std::uniform_int_distribution<> distY(animal->getCollisionRadius(), this->fieldHeight - animal->getCollisionRadius());
    int yCoord = distY(gen);
    animal->setCoords(xCoord, yCoord);
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
