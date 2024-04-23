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

void Animals::move(sf::Vector2f direction, float delta, float time_scale){
    sf::Vector2f newPosition = this->position + this->moveSpeed * delta * direction * time_scale;
    if (this->prev_position == sf::Vector2f(-1.0f, -1.0f)){
        this->prev_position = this->position; 
    }
    sf::Vector2f delta_coords = newPosition - this->prev_position;
    if (delta_coords.x * delta_coords.x + delta_coords.y * delta_coords.y > 0.01 * this->collisionRadius * this->collisionRadius) {
        if (delta_coords.x > 0){
            lookDirection=true;
        }else{
            lookDirection=false;            
        }
        this->prev_position = this->position;
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

string Animals::getTypeName(){
    return this->typeName;
}
//possible attractors and repulsors inputs: Boar, Cow, Fox, Goose, Gorilla, Pig, Sheep, Wolf
sf::Vector2f Animals::aiDirection(std::vector<Animals*>* animalArr, bool repulsorPriority = true, float time_scale = 1){
    sf::Vector2f entityDir = sf::Vector2f(0.0f, 0.0f);
    Animals* closestRep = NULL;
    Animals* closestAttr = NULL;

    for (int j = 0; j < this->repulsors.size(); j++){
        if (closestRep != NULL){
            break;
        }
        for (int i = 0; i < animalArr->size(); i++){
            if (((*animalArr)[i] == this || ((*animalArr)[i]->alive == false))){
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
            if ((*animalArr)[i] == this || ((*animalArr)[i]->alive == false)){
                continue;
            }
            if (this->getSqrDistanceTo((*animalArr)[i]) < 25*this->viewRarius*this->viewRarius){
                if ((this->typeName==(*animalArr)[i]->typeName) && ((*animalArr)[i]->typeName == this->attractors[j]) && (this->has_eaten) && (this->reproduct_clock.getElapsedTime().asSeconds() * time_scale > this->reproduction_max)){
                    if (closestAttr == NULL){
                        closestAttr = (*animalArr)[i];
                        continue;
                    }
                    if (this->getSqrDistanceTo(closestAttr) > this->getSqrDistanceTo((*animalArr)[i])){
                        closestAttr = (*animalArr)[i];
                    }
                }
            }
            if (this->getSqrDistanceTo((*animalArr)[i]) < this->viewRarius*this->viewRarius){
                if ((*animalArr)[i]->typeName == this->attractors[j]){
                    if ((*animalArr)[i]->typeName == this->typeName){
                        continue;
                    }
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
        if (reproduct_clock.getElapsedTime().asSeconds() > idle_sec_count + idle_change_time / time_scale){
            idle_sec_count = floor(reproduct_clock.getElapsedTime().asSeconds());
            // std::random_device rd;   // non-deterministic generator
            // std::mt19937 gen(rd());  // to seed mersenne twister.
            // std::uniform_int_distribution<> dist(0, 100);
            // float angle = dist(gen);
            float angle = this->random_seed * 30;
            idle_direction = sf::Vector2f(sin(angle/50*3.14),cos(angle/50*3.14));
            this->random_seed += 2;
        }
        return idle_direction;
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
        if ((forcedReturn) && (closestRep==NULL)){
            this->forcedReturn = false;
            return -diff/abs;
        }
        this->forcedReturn = false;
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
        if ((forcedReturn) && (closestAttr!=NULL)){
            this->forcedReturn = false;
            return -diff/abs;
        }
        this->forcedReturn = false;
        return diff/abs;
    }
}
//also checks for reproduction
bool Animals::foodCheck(std::vector<Animals*>* animalArr, float time_scale){
    bool repr_check = false;
    for (int i = 0; i < animalArr->size(); i++){
        // cout << (*animalArr)[i]->typeName << endl;
        if ((this != (*animalArr)[i]) && 
        (this->getSqrDistanceTo((*animalArr)[i]) < 1.5 * (this->collisionRadius + (*animalArr)[i]->collisionRadius) * 
                                                    1.5 * (this->collisionRadius + (*animalArr)[i]->collisionRadius))){
            // cout << this->reproduct_clock.getElapsedTime().asSeconds() << endl;
            if (((*animalArr)[i]->typeName == this->typeName) && ((*animalArr)[i]->alive) && 
                (this->reproduct_clock.getElapsedTime().asSeconds() * time_scale > this->reproduction_max) && 
                ((*animalArr)[i]->reproduct_clock.getElapsedTime().asSeconds() * time_scale > (*animalArr)[i]->reproduction_max) && 
                (this->has_eaten) && (*animalArr)[i]->has_eaten){
                    repr_check = true;
                    cout << "repr_check set to true" << endl;
                    this->reproduct_clock.restart();
                    this->idle_sec_count = 0;
                    (*animalArr)[i]->reproduct_clock.restart();
            }
            for (int j = 0; j < this->food.size(); j++){
                if (((*animalArr)[i]->typeName == this->food[j]) && ((*animalArr)[i]->alive)){
                    (*animalArr)[i]->alive = false;
                    (*animalArr)[i]->deathAnimationPercent = 100;
                    cout << this->typeName << " eaten " << (*animalArr)[i]->typeName << endl;
                    this->has_eaten = true;
                    this->food_clock.restart();
                }
            }
        }
    }
    if (this->food_clock.getElapsedTime().asSeconds() * time_scale > this->food_max){
        this->alive = false;
        this->has_eaten = false;
        this->deathAnimationPercent = 100;
    }
    return repr_check;
}



Animals::Animals(){
    this->forcedReturn = false;
    this->alive = true;
    this->lookDirection = true;
    this->prev_position = sf::Vector2f(-1.0f, -1.0f);
    this->needs_food = true;
    this->food_max = 10.0f;
    this->reproduction_max = 3.0f;
    this->idle_sec_count = 0;
    this->idle_change_time = 15;
    this->has_eaten = false;
}