#include "Cow.hpp"
void Cow::say(){
    cout << "I am a cow, muuuu" << endl;
}
Cow::Cow(){
    this->sprite = "Cow.png";
    this->typeName = "Cow";

    this->repulsors.push_back("Fox");
    this->repulsors.push_back("Wolf");
    this->attractors.push_back("Bush");
    this->attractors.push_back("Cow");

    this->food.push_back("Bush");
    
    this->needs_food = true;
    this->food_max = 85.0f;
    this->reproduction_max = 20.0f;

    this->collisionRadius = 8;
    this->viewRarius = 200/3;
    this->moveSpeed=10;
}
