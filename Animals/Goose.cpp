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

    this->collisionRadius = 8*3;
    this->viewRarius = 100;
    this->moveSpeed=10*3;
}