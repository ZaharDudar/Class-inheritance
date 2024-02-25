#include "Animals.hpp"
#include <cmath>
void Animals::setCoords(int xCoord, int yCoord){
    this->position = sf::Vector2f(xCoord, yCoord);
}
//true for colliding, false for not colliding
bool Animals::circleCollision(Animals* animal){
    sf::Vector2f diff = this->position - animal->position;
    return (diff.x*diff.x + diff.y*diff.y) < 
            ((this->collisionRadius + animal->collisionRadius) * 
            (this->collisionRadius + animal->collisionRadius));
};

void Animals::move(sf::Vector2f direction, float delta){
    sf::Vector2f newPosition = this->position + delta * direction * this->moveSpeed;
    setCoords(newPosition.x, newPosition.y);
}

float Animals::getCollisionRadius(){
    return this->collisionRadius;
}

float Animals::getSqrDistanceTo(Animals* animal){
    sf::Vector2f distance = this->position - animal->position;
    return distance.x*distance.x + distance.y*distance.y;
}
//possible attractors and repulsors inputs: Boar, Cow, Fox, Goose, Gorilla, Pig, Sheep, Wolf
sf::Vector2f Animals::aiDirection(std::vector<Animals*>* animalArr, bool repulsorPriority = true){
    sf::Vector2f entityDir = sf::Vector2f(0.0f, 0.0f);
    Animals* closestRep = NULL;
    Animals* closestAttr = NULL;

    for (int i = 0; i < animalArr->size(); i++){
        if ((*animalArr)[i] == this){
            continue;
        }
        for (int j = 0; j < this->attractors.size(); j++){
            if ((typeid((*animalArr)[i]).name() == (this->attractors)[j]) || 
                (this->getSqrDistanceTo(closestAttr) > this->getSqrDistanceTo((*animalArr)[i]))){
                if (closestAttr == NULL){
                    closestAttr = (*animalArr)[i];
                    break;
                }
            }
        }
        for (int j = 0; j < this->repulsors.size(); j++){
            if ((typeid((*animalArr)[i]).name() == (this->repulsors)[j]) || 
                (this->getSqrDistanceTo(closestRep) > this->getSqrDistanceTo((*animalArr)[i]))){
                if (closestRep == NULL){
                    closestRep = (*animalArr)[i];
                    break;
                }
            }
        }
    }
    if (repulsorPriority){
        sf::Vector2f diff = closestRep->position - this->position;
        float abs = sqrt(diff.x*diff.x + diff.y+diff.y);
        return diff/abs;
    }else{
        sf::Vector2f diff = this->position - closestAttr->position;
        float abs = sqrt(diff.x*diff.x + diff.y+diff.y);
        return diff/abs;
    }
}