#include "plot.hpp"
#include <iostream>

void plot::update(){
    if(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - lastUpdate > 1000000/updFrq){
        maxVal=0;
        animals = f->getAnimalArr();
        for(int dataPos=0; dataPos<dataSize-1; dataPos++){
            data[dataPos] = data[dataPos+1];
            if(data[dataPos]>maxVal){
                maxVal=data[dataPos];
            }
        }
        data[dataSize-1] = 0;
        for(int id=0; id < animals.size();id++){
            if((*animals[id]).alive){
                if(trakingType == "Predators"){
                    if(dynamic_cast<Predators*>(animals[id])){
                        data[dataSize-1]++;
                    }
                }
                else if(trakingType == "Herbivores"){
                    if(dynamic_cast<Herbivores*>(animals[id]) && string(typeid(*animals[id]).name()).find("Bush") == std::string::npos){
                        data[dataSize-1]++;
                    }
                }
                else if (string(typeid(*animals[id]).name()).find(trakingType) != std::string::npos) {
                    data[dataSize-1]++;
                }
            }
        }
        if(data[dataSize-1]>maxVal){
            maxVal=data[dataSize-1];
        }
        lastUpdate = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    }
}

plot::plot(int x, int y, int h, int w, int dataSize, std::string text, Field *f, string trObjName): pos(sf::Vector2f(x,y)), size(sf::Vector2f(h,w)), dataSize(dataSize), text(text), f(f),trakingType(trObjName) {
    bg.setFillColor(bgColor);
    bg.setPosition(pos);
    bg.setSize(size);
    data = new int[dataSize];
    for(int i=0;i<dataSize;i++){
        data[i]=0;
    }
    font.loadFromFile("./fonts/MetalMania.ttf");
    // font.loadFromFile("./fonts/metal2.otf");
    // font.loadFromFile("./fonts/metal3.ttf");
    // font.loadFromFile("./fonts/metal4.ttf");
};


void plot::plotOnWin(sf::RenderWindow *w){
        sf::Text plotName;
        plotName.setFont(font);
        plotName.setString(text + " - " + std::to_string(data[dataSize-1]));
        // plotName.setString("HI");
        plotName.setPosition(pos + sf::Vector2f(5,5));
        plotName.setCharacterSize(24);
        plotName.setFillColor(sf::Color::Red);

        vector<sf::Vertex> line;
        for(int i=0; i<dataSize; i++){
            line.push_back(sf::Vertex(sf::Vector2f((float)(size.x-20)/dataSize * i + 10, size.y - (float)(size.y-45)/maxVal * data[i] - 5)+pos,sf::Color::Red));
        }
        w->draw(bg);
        w->draw(&line[0], line.size(),sf::LinesStrip);
        w->draw(plotName);
}