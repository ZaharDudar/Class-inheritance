#include "Cow.hpp"
void Cow::say(){
    cout << "I am a cow, muuuu" << endl;
}
Cow::Cow(){
    this->sprite = "Cow.png";
    this->typeName = "Cow";

    this->repulsors.push_back("Fox");
    this->repulsors.push_back("Wolf");
    this->attractors.push_back("Cow");
    this->attractors.push_back("Bush");

    this->food.push_back("Bush");
    
    this->collisionRadius = 8*3;
    this->viewRarius = 200;
    this->moveSpeed=10*3;
}
