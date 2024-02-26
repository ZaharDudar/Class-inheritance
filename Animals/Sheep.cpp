#include "Sheep.hpp"
void Sheep::say(){
    cout << "I am a sheep, beeee" << endl;
}
Sheep::Sheep(){
    this->sprite = "Sheep.png";
    this->typeName = "Sheep";
   
    this->repulsors.push_back("Fox");
    this->repulsors.push_back("Wolf");
    this->attractors.push_back("Sheep");
    
    this->viewRarius = 150;
    this->collisionRadius = 8*3;
    this->moveSpeed=10;
}