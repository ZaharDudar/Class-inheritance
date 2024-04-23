#include "Boar.hpp"
void Boar::say(){
    std::cout<<"I'm boar, Rhhh!\n";
}
Boar::Boar(){
    this->sprite = "Boar.png";
    this->typeName = "Boar";

    this->attractors.push_back("Fox");
    this->attractors.push_back("Wolf");
    this->attractors.push_back("Boar");

    this->food.push_back("Fox");
    this->food.push_back("Wolf");

    this->needs_food = true;
    this->food_max = 40.0f;
    this->reproduction_max = 20.0f;

    this->collisionRadius = 8;
    this->viewRarius = 500;
    this->moveSpeed = 20;
}