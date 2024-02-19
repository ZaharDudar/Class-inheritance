#include <iostream>
#include "./Animals/Food.hpp"
#include "./Animals/Animals.hpp"
#include "./Animals/Wolf.hpp"
#include "./Animals/Bear.hpp"
#include "./Animals/Fox.hpp"
#include "./Animals/Tiger.hpp"
#include "./Animals/Bird.hpp"
#include "./Animals/Elephant.hpp"
#include "./Animals/Cow.hpp"
#include "./Animals/Horse.hpp"


int main(){
    Animals *zoo[8];
    Food *food[2];
    zoo[0] = new Wolf;
    zoo[1] = new Bear;
    zoo[2] = new Fox;
    zoo[3] = new Tiger;

    zoo[4] = new Bird;
    zoo[5] = new Cow;
    zoo[6] = new Horse;
    zoo[7] = new Elephant;
    
    food[0] = new Meat("Оленина");
    food[1] = new Hearbs("Картоха");


    for(int i=0; i<8;i++){
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

    for(int i=0; i<8;i++){
        delete zoo[i];
    }
    for(int j=0; j<2;j++){
        delete food[j];
    }
}