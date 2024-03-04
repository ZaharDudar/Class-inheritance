#include "Animals.hpp"

void Animals::setCoords(float xCoord, float yCoord){
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
    sf::Vector2f newPosition = this->position + this->moveSpeed * delta * direction;
    if(direction.x > 0) {
        lookDirection=true;
    }
    else{
        lookDirection=false;
    }
    setCoords(newPosition.x,newPosition.y);
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

    for (int j = 0; j < this->repulsors.size(); j++){
        if (closestRep != NULL){
            break;
        }
        for (int i = 0; i < animalArr->size(); i++){
            if ((*animalArr)[i] == this){
                continue;
            }
            if (this->getSqrDistanceTo((*animalArr)[i]) < this->viewRarius*this->viewRarius){
                if ((*animalArr)[i]->typeName == this->repulsors[j]){
                    if (closestRep == NULL){
                        closestRep = (*animalArr)[i];
                        continue;
                    }
                    if (this->getSqrDistanceTo(closestRep) > this->getSqrDistanceTo((*animalArr)[i])){
                        closestRep = (*animalArr)[i];
                    }
                }
            }
        }
    }
    for (int j = 0; j < this->attractors.size(); j++){
        if (closestAttr != NULL){
            break;
        }
        for (int i = 0; i < animalArr->size(); i++){
            if ((*animalArr)[i] == this){
                continue;
            }
            if (this->getSqrDistanceTo((*animalArr)[i]) < this->viewRarius*this->viewRarius){
                if ((*animalArr)[i]->typeName == this->attractors[j]){
                    if (closestAttr == NULL){
                        closestAttr = (*animalArr)[i];
                        continue;
                    }
                    if (this->getSqrDistanceTo(closestAttr) > this->getSqrDistanceTo((*animalArr)[i])){
                        closestAttr = (*animalArr)[i];
                    }
                }
            }
        }
    }

    if(closestRep==NULL and closestAttr==NULL){
        return sf::Vector2f(0,0);
    }

    sf::Vector2f diff;
    if (repulsorPriority){
        if(closestRep!=NULL){
            diff = -closestRep->position + this->position;
        }
        else{
            diff = -this->position + closestAttr->position;
            if (this->getSqrDistanceTo(closestAttr) < this->getCollisionRadius()*closestAttr->getCollisionRadius()){
                this->forcedReturn = true;
                closestAttr->forcedReturn = true;
            }
        }
        float abs = sqrt(diff.x*diff.x + diff.y*diff.y);
        // std::cout<<diff.x/abs<<" "<<diff.y/abs<<"\n";
        if (forcedReturn){
            this->forcedReturn = false;;
            return -diff/abs;
        }
        return diff/abs;
    }else{
        if(closestAttr!=NULL){
            diff = closestAttr->position - this->position;
            if (this->getSqrDistanceTo(closestAttr) < this->getCollisionRadius()*closestAttr->getCollisionRadius()){
                this->forcedReturn = true;
                closestAttr->forcedReturn = true;
            }
        }
        else{
            diff = -closestRep->position + this->position;
        }           
        float abs = sqrt(diff.x*diff.x + diff.y*diff.y);
        // std::cout<<diff.x/abs<<" "<<diff.y/abs<<"\n";
        if (forcedReturn){
            this->forcedReturn = false;
            return -diff/abs;
        }
        return diff/abs;
    }
}
void Animals::foodCheck(std::vector<Animals*>* animalArr){
    for (int i = 0; i < animalArr->size(); i++){
        if (this->getSqrDistanceTo((*animalArr)[i]) < 1.5 * (this->collisionRadius + (*animalArr)[i]->collisionRadius)){
            for (int j = 0; j < this->food.size(); j++){
                if ((*animalArr)[i]->typeName == this->food[j]){
                    (*animalArr)[i]->alive = false;
                    return;
                }
            }
        }
    }
}

Animals::Animals(){
    this->forcedReturn = false;
    this->alive = true;
}