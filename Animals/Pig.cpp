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
    
    this->viewRarius = 150;
    this->collisionRadius = 8*3;
    this->moveSpeed=10*3;
}