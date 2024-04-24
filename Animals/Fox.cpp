#include "Fox.hpp"
void Fox::say(){
    std::cout<<"What does fox say?!\n";
}
Fox::Fox(){
    this->sprite = "Fox.png";
    this->typeName = "Fox";

    this->attractors.push_back("Sheep");
    this->attractors.push_back("Pig");
    this->attractors.push_back("Cow");
    this->attractors.push_back("Goose");
    this->attractors.push_back("Fox");

    this->repulsors.push_back("Boar");
    this->repulsors.push_back("Gorilla");

    this->food.push_back("Sheep");
    this->food.push_back("Goose");
    this->food.push_back("Pig");
    this->food.push_back("Cow");

    this->needs_food = true;
    this->food_max = 60.0f;
    this->reproduction_max = 20.0f;

    this->collisionRadius = 8;
    this->viewRarius = 300;
    this->moveSpeed=15;
}