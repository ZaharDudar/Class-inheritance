#include <iostream>
#include "Food.hpp"
#include "Animals.hpp"
#include "Wolf.hpp"
#include "Bear.hpp"
#include "Fox.hpp"
#include "Tiger.hpp"



int main(){
    Animals *zoo[4];
    Food *food[2];
    zoo[0] = new Wolf;
    zoo[1] = new Bear;
    zoo[2] = new Fox;
    zoo[3] = new Tiger;
    food[0] = new Meat("Оленина");
    food[1] = new Hearbs("Картоха");


    for(int i=0; i<4;i++){
        zoo[i]->say();
        for(int j=0; j<2;j++){
            if(zoo[i]->canEat(food[j]))
            {
                std::cout<<"Can eat: ";
                food[j]->printName();
                std::cout<<'\n';
            }
        }
    }

    for(int i=0; i<4;i++){
        delete zoo[i];
    }
    for(int j=0; j<2;j++){
        delete food[j];
    }
}