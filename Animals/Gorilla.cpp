#include "Gorilla.hpp"
void Gorilla::say(){
    std::cout<<"I'm Gorilla, ua ua ua \n";
}
Gorilla::Gorilla(){
    this->sprite = "Gorilla.png";
    this->typeName = "Gorilla";

    this->attractors.push_back("Fox");
    this->attractors.push_back("Wolf");
    this->attractors.push_back("Gorilla");
    this->attractors.push_back("Bush");

    this->food.push_back("Fox");
    this->food.push_back("Wolf");
    this->food.push_back("Bush");

    this->needs_food = true;
    this->food_max = 100.0f;
    this->reproduction_max = 100.0f;

    this->viewRarius = 200/3;
    this->collisionRadius = 16;
    this->moveSpeed=10;
}