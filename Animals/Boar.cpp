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

    this->collisionRadius = 8*3;
    this->viewRarius = 600;
    this->moveSpeed = 20;
}