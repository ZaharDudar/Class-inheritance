#include "Bush.hpp"
void Bush::say(){
    std::cout<<"I'm bush, wtf!\n";
}
Bush::Bush(){
    this->sprite = "Bush.png";
    this->typeName = "Bush";
    
    this->needs_food = false;
   

    this->moveSpeed = 0;
    this->collisionRadius = 8;
    this->needs_food = false;
}