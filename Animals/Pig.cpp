#include "Pig.hpp"
void Pig::say(){
    cout << "I am a pig, rhh rhh" << endl;
}
Pig::Pig(){
    this->sprite = "Pig.png";
    this->typeName = "Pig";

    this->repulsors.push_back("Fox");
    this->repulsors.push_back("Wolf");
    this->attractors.push_back("Pig");
    this->attractors.push_back("Bush");

    this->food.push_back("Bush");
    
    this->needs_food = true;
    this->food_max = 70.0f;
    this->reproduction_max = 20.0f;

    this->viewRarius = 150/3;
    this->collisionRadius = 8;
    this->moveSpeed=10;
}