#include "Wolf.hpp"
void Wolf::say(){
    std::cout<<"I'm grey wolf, wof wof!\n";
}
Wolf::Wolf(){
    this->sprite = "Wolf.png";
    this->typeName = "Wolf";
    
    this->attractors.push_back("Sheep");
    this->attractors.push_back("Pig");
    this->attractors.push_back("Cow");
    this->attractors.push_back("Wolf");
    this->attractors.push_back("Goose");

    this->repulsors.push_back("Boar");
    this->repulsors.push_back("Gorilla");
    this->moveSpeed=100;
    
    this->food.push_back("Wolf");
    this->food.push_back("Sheep");
    this->food.push_back("Goose");
    this->food.push_back("Pig");
    this->food.push_back("Cow");

    this->needs_food = true;
    this->food_max = 60.0f;
    this->reproduction_max = 20.0f;

    this->viewRarius = 250;
    this->collisionRadius = 8;
    this->moveSpeed=15;
}