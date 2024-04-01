#include "Goose.hpp"
void Goose::say(){
    cout << "I am bird, can fly" << endl;
}
Goose::Goose(){
    this->sprite = "Goose.png";
    this->typeName = "Goose";

    this->repulsors.push_back("Fox");
    this->repulsors.push_back("Wolf");
    this->attractors.push_back("Goose");
    this->attractors.push_back("Bush");

    this->food.push_back("Bush");
    
    this->needs_food = true;
    this->food_max = 70.0f;
    this->reproduction_max = 15.0f;

    this->collisionRadius = 8;
    this->viewRarius = 100/3;
    this->moveSpeed=10;
}