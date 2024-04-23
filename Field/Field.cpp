#include "Field.hpp"
#include <vector>
#include <random>
#include <typeinfo>

Field::Field(){
    this->previousFrameTime = getMainTime();
    this->currentFrameTime = getMainTime();
    this->fieldWidth = 1200;
    this->fieldHeight = 1200;
    this->bush_spawn_cd = 1.5f;
    this->last_bush_spawned_time = this->getMainTime();
    this->time_scale = 1;
    this->random_seed = 0;
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
        if ((animalArr[i]->alive) && (animalArr[i]->getTypeName() != "Bush")){
        animalArr[i]->move(animalArr[i]->aiDirection(&(this->animalArr), true, this->time_scale), this->currentFrameTime - this->previousFrameTime, this->time_scale);
        if (animalArr[i]->foodCheck(&(this->animalArr), this->time_scale)){
            cout << "boutta spawn " << animalArr[i]->getTypeName() << endl;
            if (animalArr[i]->getTypeName() == "Wolf")
            spawnAnimal<Wolf>(animalArr[i]->position + sf::Vector2f(20, 20));
            else if (animalArr[i]->getTypeName() == "Boar")
            spawnAnimal<Boar>(animalArr[i]->position + sf::Vector2f(20, 20));
            else if (animalArr[i]->getTypeName() == "Fox")
            spawnAnimal<Fox>(animalArr[i]->position + sf::Vector2f(20, 20));
            else if (animalArr[i]->getTypeName() == "Goose")
            spawnAnimal<Goose>(animalArr[i]->position + sf::Vector2f(20, 20));
            else if (animalArr[i]->getTypeName() == "Pig")
            spawnAnimal<Pig>(animalArr[i]->position + sf::Vector2f(20, 20));
            else if (animalArr[i]->getTypeName() == "Cow")
            spawnAnimal<Cow>(animalArr[i]->position + sf::Vector2f(20, 20));
            else if (animalArr[i]->getTypeName() == "Gorilla")
            spawnAnimal<Gorilla>(animalArr[i]->position + sf::Vector2f(20, 20));
            else if (animalArr[i]->getTypeName() == "Sheep")
            spawnAnimal<Sheep>(animalArr[i]->position + sf::Vector2f(20, 20));
        }
        }
    }
    if ((this->getMainTime() - this->last_bush_spawned_time)*this->time_scale > this->bush_spawn_cd){
        spawnAnimal<Bush>();
        this->last_bush_spawned_time = this->getMainTime();
        // cout << "bush spawned\n";
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

void Field::spawnAnimal(std::string name, int n, sf::Vector2f pos){
    for(int i=0;i<n;i++){
        if (name == "Wolf")
            this->spawnAnimal<Wolf>(pos);
        else if (name == "Boar")
            this->spawnAnimal<Boar>(pos);
        else if (name == "Fox")
            this->spawnAnimal<Fox>(pos);
        else if (name == "Goose")
            this->spawnAnimal<Goose>(pos);
        else if (name == "Pig")
            this->spawnAnimal<Pig>(pos);
        else if (name == "Cow")
            this->spawnAnimal<Cow>(pos);
        else if (name == "Gorilla")
            this->spawnAnimal<Gorilla>(pos);
        else if (name == "Sheep")
            this->spawnAnimal<Sheep>(pos);
        else if (name == "Bush")
            this->spawnAnimal<Bush>(pos);
        else 
            throw std::invalid_argument( "recieved invalid type argument to attach funck" );
    }
}