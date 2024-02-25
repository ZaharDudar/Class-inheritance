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
    Drawer drawer(sunnyHill.fieldWidth, sunnyHill.fieldHeight);
    sunnyHill.spawnAnimal("Wolf");
    while(true){
        sunnyHill.update();
        drawer.draw(sunnyHill.getAnimalArr());
    }
}