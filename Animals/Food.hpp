#pragma once
#include <string>
#include <iostream>

class Food
{
protected:
    std::string name = "";
    bool meat=false;
    Food(){};
public:
    bool isMeat() {return meat;};
    void printName(){
        std::cout<<name;
    }
    ~Food(){};
};

class Meat : public Food {
    public:
        Meat(std::string name){
            this->meat = true;
            this->name = name;
        }
};
class Hearbs : public Food {
    public:
        Hearbs(std::string name){
            this->meat = false;
            this->name = name;
        }
};