#include <iostream>
#include <fstream>
#include "./Animals/Food.hpp"
#include "./Animals/Animals.hpp"
#include "./Animals/Wolf.hpp"
#include "./Animals/Fox.hpp"
#include "./Animals/Cow.hpp"
#include "./Field/Field.hpp"
#include "./Drawer/Drawer.hpp"
void readFile(fstream& cfg, Field& f, string* simName);

int main(int argc, char **argv){
    Field sunnyHill;
    sunnyHill.time_scale = 3;
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
    fstream config;
    string simName;
    config.open(argv[1]);
    readFile(config, sunnyHill, &simName);
    ofstream log;
    log.open("./logs/"+simName+".log");

    bool startLog=false;
    unsigned long long int step=0;
    // sunnyHill.spawnAnimal<Pig>();
    while(true){
        sunnyHill.update();
        drawer.draw(sunnyHill.getAnimalArr());
        vector<plot> plots = drawer.getPlots();

        step++;
        log<<"step "<<step<<"\n";
        for(int an=0; an<plots.size();an++){
            log<<plots[an].getName() <<" "<< std::to_string(plots[an].getVal())<<startLog<<"\n";
        }
        if(plots[0].getVal() != 0 and plots[1].getVal() != 0 and !startLog) startLog = true;// Сделать нормально
        for(int an=0; an<plots.size();an++){

            if(plots[an].getVal() <= 1 and startLog){
                log.close();
                return 0;
            }
        }
    }
}
void readFile(fstream& cfg, Field& f, string* simName){
    std::string line;
    std::string tmp;
    int dataPos=0;
    int timeScale=0;
    std::string animalName;
    int x,y,n;
    if (cfg.is_open()) {
        std::getline(cfg, line);
        for(int i=0; i<line.length();i++){
            if(line[i]!=' '){
                tmp+=line[i];
            }
            else{
                if(dataPos == 0){
                    *simName = tmp;
                }
                tmp = "";
                dataPos++;
            }
        }
        if(dataPos == 1){
            f.time_scale = stoi(tmp);
        }
        tmp = ""; 
        dataPos=0;
        while (cfg) {
            std::getline(cfg, line);
            if(!cfg) break;
            // std::cout<<line;
            dataPos=0;
            for(int i=0; i<line.length();i++){
                if(line[i]!=' '){
                    tmp+=line[i];
                }
                else{
                    if(dataPos == 0){
                        animalName = tmp;
                    }
                    if(dataPos == 1){
                        x = stoi(tmp);
                    }
                    if(dataPos == 2){
                        y = stoi(tmp);
                    }
                    tmp = "";
                    dataPos++;
                }
            }
            n = stoi(tmp);
            tmp = ""; 
            f.spawnAnimal(animalName, n, sf::Vector2f(x,y));
        }
    }
}