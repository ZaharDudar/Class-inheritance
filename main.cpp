#include <iostream>
#include "./Animals/Food.hpp"
#include "./Animals/Animals.hpp"
#include "./Animals/Wolf.hpp"
#include "./Animals/Fox.hpp"
#include "./Animals/Cow.hpp"
#include "./Field/Field.hpp"
#include "./Drawer/Drawer.hpp"

int main(){
    Field sunnyHill;
    Drawer drawer(sunnyHill.fieldWidth, sunnyHill.fieldHeight,2);
    sunnyHill.spawnAnimal("Wolf");
    sunnyHill.spawnAnimal("Sheep");
    sunnyHill.spawnAnimal("Gorilla");
    sunnyHill.spawnAnimal("Goose");
    sunnyHill.spawnAnimal("Cow");
    sunnyHill.spawnAnimal("Fox");
    sunnyHill.spawnAnimal("Boar");
     sunnyHill.spawnAnimal("Pig");

    while(true){
        sunnyHill.update();
        drawer.draw(sunnyHill.getAnimalArr());
    }
}