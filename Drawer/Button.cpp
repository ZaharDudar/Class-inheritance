#include "Button.hpp"
Button::Button(sf::Sprite sp, sf::Texture tx): selfSprite(sp), selfType(NONE), field(nullptr), selfTexture(tx){}
Button::Button(sf::Sprite sp, sf::Texture tx, Field *field, string spawnName): selfSprite(sp), selfType(SPAWNBUTTON), field(field), spawnArg(spawnName),selfTexture(tx) {}

void Button::press(){
    seleted = !seleted;
    cout<<spawnArg<<'\n';
}
void Button::useOnMap(int x, int y){
    if(selfType == SPAWNBUTTON){
        if (spawnArg == "Wolf")
            (*field).spawnAnimal<Wolf>(sf::Vector2f(x,y));
        else if (spawnArg == "Boar")
            (*field).spawnAnimal<Boar>(sf::Vector2f(x,y));
        else if (spawnArg == "Fox")
            (*field).spawnAnimal<Fox>(sf::Vector2f(x,y));
        else if (spawnArg == "Goose")
            (*field).spawnAnimal<Goose>(sf::Vector2f(x,y));
        else if (spawnArg == "Pig")
            (*field).spawnAnimal<Pig>(sf::Vector2f(x,y));
        else if (spawnArg == "Cow")
            (*field).spawnAnimal<Cow>(sf::Vector2f(x,y));
        else if (spawnArg == "Gorilla")
            (*field).spawnAnimal<Gorilla>(sf::Vector2f(x,y));
        else if (spawnArg == "Sheep")
            (*field).spawnAnimal<Sheep>(sf::Vector2f(x,y));
        else 
            throw std::invalid_argument( "recieved invalid type argument to attach funck" );
    }
}
bool Button::checkPress(sf::Vector2f pos){
    sf::Vector2f selfPos = selfSprite.getPosition();
    sf::Vector2u selfSize = selfTexture.getSize();
    sf::Vector2f scaleModifier = selfSprite.getScale();
    scaleModifier.x /= 4; 
    // cout<<selfPos.x<<' '<<selfPos.y<<"|";
    // cout<<pos.x<<" "<<pos.y<<"|";
    // cout<<selfPos.x + selfSize.x*scaleModifier.x << " " << selfPos.y + selfSize.y*scaleModifier.y<<"\n";
    return (pos.x >= selfPos.x and pos.x <= selfPos.x + selfSize.x*scaleModifier.x) and (pos.y >= selfPos.y and pos.y <= selfPos.y + selfSize.y*scaleModifier.y);
}