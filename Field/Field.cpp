#include "Field.hpp"
#include <vector>
#include <random>
#include <typeinfo>

Field::Field(){
    this->previousFrameTime = getMainTime();
    this->currentFrameTime = getMainTime();
    this->fieldWidth = 1200;
    this->fieldHeight = 1200;
}

Field::~Field(){
    animalArr.clear();
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
    // for (int i = 0; i < animalArr.size(); i++){-----------------animalArr cout
    //     cout << animalArr[i]->getTypeName() << " ";
    // }
    // cout << endl;
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
