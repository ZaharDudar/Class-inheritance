#include "Wolf.hpp"
void Wolf::say(){
    std::cout<<"I'm grey wolf, wof wof!\n";
}
Wolf::Wolf(){
    this->sprite = "Wolf.png";
    this->typeName = "Wolf";
    this->attractors.push_back("Sheep");
    this->attractors.push_back("Wolf");
    this->repulsors.push_back("Gorilla");
}