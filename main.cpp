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
    Drawer drawer(sunnyHill.fieldWidth, sunnyHill.fieldHeight, 3);
    sunnyHill.spawnAnimal("Wolf");
    sunnyHill.spawnAnimal("Goose");
    sunnyHill.spawnAnimal("Boar");
    sunnyHill.spawnAnimal("Cow");
    sunnyHill.spawnAnimal("Fox");
    sunnyHill.spawnAnimal("Pig");
    sunnyHill.spawnAnimal("Sheep");
    drawer.addSpawnButton("Wolf", &sunnyHill, 0,0,50,50);
    drawer.addSpawnButton("Boar", &sunnyHill, 0,60,50,50);
    drawer.addSpawnButton("Sheep", &sunnyHill, 60,0,50,50);
    drawer.addSpawnButton("Fox", &sunnyHill, 60,60,50,50);
    while(true){
        sunnyHill.update();
        drawer.draw(sunnyHill.getAnimalArr());
    }
}