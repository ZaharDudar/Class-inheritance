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

    this->food.push_back("Fox");
    this->food.push_back("Wolf");

    this->viewRarius = 200;
    this->collisionRadius = 16*3;
    this->moveSpeed=8*3;
}