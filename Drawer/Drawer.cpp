#include "Drawer.hpp"
#include <stdexcept>
#include "SFML/System/Vector2.hpp"
#include <filesystem>
#include <iostream>
#include <chrono>

Drawer::Drawer(int W,int H){
    this->window = new sf::RenderWindow(sf::VideoMode(W,H), "sim");
    loadTextures();
}
Drawer::Drawer(int W,int H, float scF){
    this->window = new sf::RenderWindow(sf::VideoMode(W,H), "sim");
    this->scalingFactor = scF;
    loadTextures();
}

void Drawer::loadTextures(){
    for(auto file : std::filesystem::directory_iterator("./PNG's")){
        sf::Texture texture;
        if(!texture.loadFromFile(file.path())){}
        sf::Vector2u shape = texture.getSize();
        this->textures[file.path()].push_back(texture);
        for(int frame=0;frame<=shape.x;frame+=shape.x/4){
            sf::Sprite ent;
            ent.setTexture(this->textures[file.path()].back());
            ent.setTextureRect(sf::IntRect(frame,0,shape.x/4,shape.y));
            ent.setOrigin(shape.x/8,shape.y/2);

            ent.setScale(1.0f*scalingFactor,1.0f*scalingFactor);
            this->entitySprites[file.path()].push_back(ent);

            ent.setScale(-1.0f*scalingFactor,1.0f*scalingFactor);
            this->entitySpritesReverse[file.path()].push_back(ent);
        }
    }
}
void Drawer::draw(vector<Animals*> entities){
    if(!this->window->isOpen()) {throw std::runtime_error("yr conputer has virus");}
    sf::Event ev;
    while (this->window->pollEvent(ev))
    {
        if(ev.type == sf::Event::Closed){
            window->close();
        }
    }  
    auto currentTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    window->clear();
    for(int ent_id=0; ent_id < entities.capacity(); ent_id++){
        if(currentTime - (*entities[ent_id]).lastAnimUpdate > 1000/animationFPS){
            (*entities[ent_id]).animFrame+=1;
            if((*entities[ent_id]).animFrame>=4) 
                (*entities[ent_id]).animFrame = 0;
            (*entities[ent_id]).lastAnimUpdate = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        }
        entitySprites[string{"./PNG's/"} + (*entities[ent_id]).sprite][(*entities[ent_id]).animFrame].setPosition((*entities[ent_id]).position.x,(*entities[ent_id]).position.y );
        entitySpritesReverse[string{"./PNG's/"} + (*entities[ent_id]).sprite][(*entities[ent_id]).animFrame].setPosition((*entities[ent_id]).position.x,(*entities[ent_id]).position.y );
        
        if((*entities[ent_id]).lookDirection){
            window->draw(entitySprites[string{"./PNG's/"} + (*entities[ent_id]).sprite][(*entities[ent_id]).animFrame]);
        }
        else{
            window->draw(entitySpritesReverse[string{"./PNG's/"} + (*entities[ent_id]).sprite][(*entities[ent_id]).animFrame]);
        }
    }
    window->display();
    
}