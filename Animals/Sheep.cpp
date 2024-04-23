#include "Sheep.hpp"
void Sheep::say(){
    cout << "I am a sheep, beeee" << endl;
}
Sheep::Sheep(){
    this->sprite = "Sheep.png";
    this->typeName = "Sheep";
   
    this->repulsors.push_back("Fox");
    this->repulsors.push_back("Wolf");
    this->attractors.push_back("Bush");
    this->attractors.push_back("Sheep");
    

    this->food.push_back("Bush");
    
    this->needs_food = true;
    this->food_max = 70.0f;
    this->reproduction_max = 20.0f;

    this->viewRarius = 150;
    this->collisionRadius = 8;
    this->moveSpeed=10;
}