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
    if(stepUpdateButtons){stepUpdateButtons=false;}
    while (this->window->pollEvent(ev))
    {
        if(ev.type == sf::Event::Closed){
            window->close();
        }
        if(ev.type == sf::Event::MouseButtonPressed){
            if(ev.mouseButton.button == sf::Mouse::Left)
                updateGui(ev.mouseButton.x,ev.mouseButton.y);
                if(!stepUpdateButtons){
                    for(int b_id=0;b_id<buttons.size(); b_id++){
                        if(buttons[b_id].seleted){
                            buttons[b_id].useOnMap(ev.mouseButton.x,ev.mouseButton.y);
                        }
                    }
                }
        }
    }  
    auto currentTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    window->clear();
    for(int ent_id=0; ent_id < entities.size(); ent_id++){
        
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
    for(int b_id = 0; b_id < buttons.size(); b_id++){
        window->draw(buttons[b_id].selfSprite);
        if(buttons[b_id].seleted){
            sf::Vector2u selfSize = buttons[b_id].selfSprite.getTexture()->getSize();
            sf::Vector2f scaleModifier = buttons[b_id].selfSprite.getScale();
            sf::RectangleShape highlight(sf::Vector2f((float)selfSize.x*scaleModifier.x, (float)selfSize.y*scaleModifier.y));
            highlight.setFillColor(sf::Color(0,0,0,100));
            highlight.setPosition(buttons[b_id].selfSprite.getPosition());
            window->draw(highlight);
        }
    }
    window->display();
    
}

void Drawer::addSpawnButton(string animName, Field *field,int x, int y, int w, int h){
    sf::Vector2u shape = textures[string{"./PNG's/"} + animName + string(".png")][0].getSize();
    sf::Sprite ent;
    ent.setTexture(textures[string{"./PNG's/"} + animName + string(".png")][0]);
    ent.setTextureRect(sf::IntRect(0,0,shape.x/4,shape.y));
    ent.setScale(4*w/shape.x,h/shape.y);
    ent.setPosition(x,y);
    buttons.push_back(Button(ent, textures[string{"./PNG's/"} + animName + string(".png")][0], field, animName));
}

void Drawer::updateGui(int x, int y){
    sf::Vector2f pos((float)x,(float)y);
    for(int b_id=0;b_id<buttons.size(); b_id++){
        if(buttons[b_id].checkPress(pos)){
            for(int i=0; i<buttons.size(); i++) {if(i!=b_id){buttons[b_id].seleted=false;}}
            stepUpdateButtons = true;
            buttons[b_id].press();
        }
    }
}
Button::Button(sf::Sprite sp, sf::Texture tx): selfSprite(sp), selfType(NONE), field(nullptr), selfTexture(tx){}
Button::Button(sf::Sprite sp, sf::Texture tx, Field *field, string spawnName): selfSprite(sp), selfType(SPAWNBUTTON), field(field), spawnArg(spawnName),selfTexture(tx) {}

void Button::press(){
    seleted = !seleted;
}
void Button::useOnMap(int x, int y){
    if(selfType == SPAWNBUTTON){
        (*field).spawnAnimal(spawnArg, sf::Vector2f(x,y));
    }
}
bool Button::checkPress(sf::Vector2f pos){
    sf::Vector2f selfPos = selfSprite.getPosition();
    sf::Vector2u selfSize = selfTexture.getSize();
    sf::Vector2f scaleModifier = selfSprite.getScale();
    return (pos.x >= selfPos.x and pos.x <= selfPos.x + selfSize.x*scaleModifier.x) and (pos.y > selfPos.y and pos.y < selfPos.y + selfSize.y*scaleModifier.y);
}