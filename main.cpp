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
    Drawer drawer(sunnyHill.fieldWidth, sunnyHill.fieldHeight, 1);
    // sunnyHill.spawnAnimal<Wolf>();
    drawer.addSpawnButton("Wolf", &sunnyHill, 20,20,50,50);
    drawer.addSpawnButton("Boar", &sunnyHill, 20,80,50,50);
    drawer.addSpawnButton("Sheep", &sunnyHill, 80,20,50,50);
    drawer.addSpawnButton("Fox", &sunnyHill, 80,80,50,50);
    drawer.addSpawnButton("Gorilla", &sunnyHill, 140,20,50,50);
    drawer.addSpawnButton("Goose", &sunnyHill, 140,80,50,50);
    drawer.addSpawnButton("Cow", &sunnyHill, 200,20,50,50);
    drawer.addSpawnButton("Pig", &sunnyHill, 200,80,50,50);


    drawer.addPlot("Predators", &sunnyHill, 10,150,300,120);
    drawer.addPlot("Herbivores", &sunnyHill, 10,290,300,120);

    // sunnyHill.spawnAnimal<Pig>();
    while(true){
        sunnyHill.update();
        drawer.draw(sunnyHill.getAnimalArr());
    }
}