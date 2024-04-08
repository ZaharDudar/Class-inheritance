#include "Drawer.hpp"
#include <stdexcept>
#include "SFML/System/Vector2.hpp"
#include <filesystem>
#include <iostream>
#include <chrono>

# include "../PerlinNoise.hpp"

Drawer::Drawer(int W,int H){
    backgroundTexture.loadFromFile("./Backgrounds/field.png");
    background.setTexture(backgroundTexture);
    sf::Vector2u shape = backgroundTexture.getSize();
    background.setScale(((float)W)/shape.x, ((float)H)/shape.y);

    
    this->window = new sf::RenderWindow(sf::VideoMode(W,H), "sim");
    buttonBackround.setFillColor(sf::Color(209, 206, 197));
    loadTextures();
}
Drawer::Drawer(int W,int H, float scF){
    backgroundTexture.loadFromFile("./Backgrounds/field.png");
    background.setTexture(backgroundTexture);
    sf::Vector2u shape = backgroundTexture.getSize();
    background.setScale(((float)W)/shape.x, ((float)H)/shape.y);

    this->window = new sf::RenderWindow(sf::VideoMode(W,H), "sim");
    buttonBackround.setFillColor(sf::Color(209, 206, 197));
    this->scalingFactor = scF;
    loadTextures();
    mapGenerator(1,0.5,2);
}

void Drawer::mapGenerator(float frequency, double threashold, int octaves){
    mapEnvTexture.loadFromFile("./Backgrounds/forest.png");
    int W = window->getSize().x;
    int H = window->getSize().y;
    std::vector<sf::IntRect> trees;
    std::vector<sf::IntRect> grass;

    trees.push_back(sf::IntRect(0,0,32,56));
    trees.push_back(sf::IntRect(32,0,32,51));
    grass.push_back(sf::IntRect(3,70,11,6));
    grass.push_back(sf::IntRect(20,70,10,4));
    grass.push_back(sf::IntRect(35,70,10,5));

    const siv::PerlinNoise::seed_type seed = (unsigned int)std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	const siv::PerlinNoise perlin{ seed };
    for(int x_n = 0; x_n < mapGenNVoxel; x_n++){
        for(int y_n = 0; y_n < mapGenNVoxel; y_n++){
            double noiseValue = perlin.octave2D_01( x_n*frequency, y_n*frequency, octaves);
            // cout<<noiseValue<<" | "<<getNumberFromNoiseTrees(noiseValue)<<" "<<getNumberFromNoiseGrass(noiseValue)<<'\n';
            for(int grass_id=0; grass_id<getNumberFromNoiseGrass(noiseValue);grass_id++){
                sf::Sprite bgTile;
                bgTile.setTexture(mapEnvTexture);
                bgTile.setTextureRect(grass[rand()%grass.size()]);
                bgTile.setPosition((float)x_n/mapGenNVoxel * W + rand()%(H/mapGenNVoxel), (float)y_n/mapGenNVoxel * H + rand()%(H/mapGenNVoxel));
                mapEnv.push_back(bgTile);
            }
        }
    }
    for(int x_n = 0; x_n < mapGenNVoxel; x_n++){
        for(int y_n = 0; y_n < mapGenNVoxel; y_n++){
            double noiseValue = perlin.octave2D_01( x_n*frequency, y_n*frequency, octaves);
            for(int tree=0; tree<getNumberFromNoiseTrees(noiseValue);tree++){
                sf::Sprite bgTile;
                bgTile.setTexture(mapEnvTexture);
                bgTile.setTextureRect(trees[rand()%trees.size()]);
                bgTile.setPosition((float)x_n/mapGenNVoxel * W + rand()%(H/mapGenNVoxel), (float)y_n/mapGenNVoxel * H + rand()%(H/mapGenNVoxel));
                mapEnv.push_back(bgTile);
            }
        }
    }
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
            
            ent.setScale(scalingFactor,scalingFactor);
            this->entitySprites[file.path()].push_back(ent);

            ent.setScale(-scalingFactor,scalingFactor);
            this->entitySpritesReverse[file.path()].push_back(ent);
        }
    }
    pistolTexture.loadFromFile("./Backgrounds/Pistol.png");
    sf::Vector2u shape = pistolTexture.getSize();
    for(int pframe=0; pframe<5; pframe++){
        sf::Sprite fr;
        fr.setTexture(pistolTexture);
        fr.setTextureRect(sf::IntRect(pframe*shape.x/5,0,shape.x/4,shape.y));
        fr.setOrigin(shape.x/5,shape.y);
        fr.setScale(pistolScale, pistolScale);
        fr.setPosition(window->getSize().x+15, window->getSize().y+20);
        pistolFrames.push_back(fr);
    }
    shotButtonTexture.loadFromFile("./Backgrounds/scope.png");
    shotButtonSp.setTexture(shotButtonTexture);
    shotButtonSp.setOrigin(shotButtonTexture.getSize().x/2, shotButtonTexture.getSize().y/2);
    shotButtonSp.setScale(shotBtScale, shotBtScale);
    shotButtonSp.setPosition(window->getSize().x-shotButtonTexture.getSize().x*shotBtScale-10,shotButtonTexture.getSize().y*shotBtScale + 10);
    shotBtBg.setPosition(window->getSize().x-shotButtonTexture.getSize().x*shotBtScale*1.5-10 - 5,shotButtonTexture.getSize().y*shotBtScale*0.5 + 10 - 6 );
    shotBtBg.setSize(sf::Vector2f(shotButtonTexture.getSize().x*shotBtScale + 12, shotButtonTexture.getSize().y*shotBtScale + 12));
    // shotBtBg.setPosition(window->getSize().x-shotButtonTexture.getSize().x*2-10 - 6, window->getSize().y+shotButtonTexture.getSize().y*2 +20 - 6 );
    shotBtBg.setFillColor(sf::Color(209, 206, 197));
}
void Drawer::draw(vector<Animals*> entities){
    auto currentTime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    if(!this->window->isOpen()) {throw std::runtime_error("yr conputer has virus");}
    sf::Event ev;
    if(stepUpdateButtons){stepUpdateButtons=false;}
    while (this->window->pollEvent(ev))
    {
        if(ev.type == sf::Event::Closed){
            window->close();
        }
        if(ev.type == sf::Event::MouseButtonPressed){
            if(ev.mouseButton.button == sf::Mouse::Left){
                updateGui(ev.mouseButton.x,ev.mouseButton.y);
                if(!stepUpdateButtons){
                    for(int b_id=0;b_id<buttons.size(); b_id++){
                        if(buttons[b_id].seleted){
                            buttons[b_id].useOnMap(ev.mouseButton.x,ev.mouseButton.y);
                        }
                    }
                }
            }
            if(ev.mouseButton.button == sf::Mouse::Right){
                if (pistolEquipted){
                    for(int ent_id=0; ent_id < entities.size(); ent_id++ ){
                        auto dir = (*entities[ent_id]).position - sf::Vector2f(ev.mouseButton.x,ev.mouseButton.y);
                        if(sqrt(dir.x*dir.x + dir.y*dir.y) < (*entities[ent_id]).getCollisionRadius() and (*entities[ent_id]).alive){
                            (*entities[ent_id]).alive = false;
                            (*entities[ent_id]).deathAnimationPercent = 100;
                        }
                    }
                    pistolAnimFrame = 0; //Запуск анимации пистолета
                }
            }
        }
    }  
    window->clear(sf::Color(10, 153, 5));
    for(int item_id=0;item_id < mapEnv.size(); item_id++){
        window->draw(mapEnv[item_id]);   
    }
    


    for(int ent_id=0; ent_id < entities.size(); ent_id++){
        
        if(currentTime - (*entities[ent_id]).lastAnimUpdate > 1000000/animationFPS){
            (*entities[ent_id]).animFrame+=1;
            if((*entities[ent_id]).animFrame>=4) 
                (*entities[ent_id]).animFrame = 0;
            (*entities[ent_id]).lastAnimUpdate = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        }
        entitySprites[string{"./PNG's/"} + (*entities[ent_id]).sprite][(*entities[ent_id]).animFrame].setPosition((*entities[ent_id]).position.x,(*entities[ent_id]).position.y );
        entitySpritesReverse[string{"./PNG's/"} + (*entities[ent_id]).sprite][(*entities[ent_id]).animFrame].setPosition((*entities[ent_id]).position.x,(*entities[ent_id]).position.y );
        
        sf::Sprite sprite;
        if((*entities[ent_id]).lookDirection){
            sprite = entitySprites[string{"./PNG's/"} + (*entities[ent_id]).sprite][(*entities[ent_id]).animFrame]; 
        }
        else{
            sprite = entitySpritesReverse[string{"./PNG's/"} + (*entities[ent_id]).sprite][(*entities[ent_id]).animFrame];
        }

        if((*entities[ent_id]).alive){
            window->draw(sprite);
        }
        else{
            if((*entities[ent_id]).deathAnimationPercent>0){
                currentTime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
                sprite.setColor(sf::Color((int)(255*(float)(*entities[ent_id]).deathAnimationPercent/100.0f),0,0));
                auto newScale = (-(float)exp(-pow((*entities[ent_id]).deathAnimationPercent,1.8)/100)+1) * sprite.getScale();
                sprite.setScale(newScale.x,newScale.y);
                (*entities[ent_id]).deathAnimationPercent -= (float)(currentTime - globalLastFrameTime)/deathAnimationDuration * 100.0f;
                window->draw(sprite);
            }
        }
    }
    window->draw(buttonBackround);
    for(int b_id = 0; b_id < buttons.size(); b_id++){
        window->draw(buttons[b_id].selfSprite);
        if(buttons[b_id].seleted){
            sf::Vector2u selfSize = buttons[b_id].selfSprite.getTexture()->getSize();
            sf::Vector2f scaleModifier = buttons[b_id].selfSprite.getScale();
            scaleModifier.x /= 4; 
            sf::RectangleShape highlight(sf::Vector2f((float)selfSize.x*scaleModifier.x, (float)selfSize.y*scaleModifier.y));
            highlight.setFillColor(sf::Color(0,255,0,100));
            highlight.setPosition(buttons[b_id].selfSprite.getPosition());
            window->draw(highlight);
        }
    }

    window->draw(shotBtBg);
    window->draw(shotButtonSp);
    if(pistolEquipted){
        sf::Sprite currentPistolFrame;
        if(pistolAnimFrame == -1){
            currentPistolFrame = pistolFrames[0];
        }
        else{
            currentPistolFrame = pistolFrames[pistolAnimFrame];
        }
        auto curPos = currentPistolFrame.getPosition();
        auto mousePos = sf::Mouse::getPosition(*window);
        int W = window->getSize().x;
        int H = window->getSize().y;
        currentPistolFrame.setPosition(curPos.x + (float)(mousePos.x - W/2)/W * pistolMoveFactor, curPos.y + (float)(mousePos.y-H/2)/H * pistolMoveFactor);

        window->draw(currentPistolFrame);
        if(currentTime - pistolAnimLastFrameTime > 1000000/pistolAnimFPS and pistolAnimFrame!=-1){
            pistolAnimFrame+=1;
            if(pistolAnimFrame>4){
                pistolAnimFrame = -1;
            }
            pistolAnimLastFrameTime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        }
        sf::RectangleShape highlight(sf::Vector2f((float)shotButtonTexture.getSize().x*shotBtScale, (float)shotButtonTexture.getSize().x*shotBtScale));
        highlight.setFillColor(sf::Color(0,255,0,100));
        highlight.setPosition(sf::Vector2f(shotButtonSp.getPosition().x - shotButtonTexture.getSize().x*shotBtScale/2, shotButtonSp.getPosition().y - shotButtonTexture.getSize().y*shotBtScale/2));
        window->draw(highlight);
    }
    for(int plot_i = 0; plot_i<plots.size();plot_i++){
        plots[plot_i].update();
        plots[plot_i].plotOnWin(window);
    }

    window->display();
    globalLastFrameTime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

void Drawer::addSpawnButton(string animName, Field *field,int x, int y, int w, int h){
    sf::Vector2f bgBPos = buttonBackround.getPosition();
    sf::Vector2f bgBSize = buttonBackround.getSize();
    if(setFirstButton){
        buttonBackround.setPosition(x-outlineBg,y-outlineBg);
        buttonBackround.setSize(sf::Vector2f(x + w + outlineBg,y + h + outlineBg));
        setFirstButton = false;
    }
    if(x < bgBPos.x){
        buttonBackround.setPosition(x-outlineBg,bgBPos.y);
    }
    if(y < bgBPos.y){
        buttonBackround.setPosition(bgBPos.x,y-outlineBg);
    }
    if(x + w > bgBSize.x + bgBPos.x){
        buttonBackround.setSize(sf::Vector2f(x + w - bgBPos.x + outlineBg,bgBSize.y));
    }
    if(y + h > bgBSize.y + bgBPos.y){
        buttonBackround.setSize(sf::Vector2f(bgBPos.x, y + h - bgBPos.y + outlineBg));
    }
    sf::Vector2u shape = textures[string{"./PNG's/"} + animName + string(".png")][0].getSize();
    sf::Sprite ent;
    ent.setTexture(textures[string{"./PNG's/"} + animName + string(".png")][0]);
    ent.setTextureRect(sf::IntRect(0,0,shape.x/4,shape.y));
    ent.setScale(4*(float)w/shape.x,(float)h/shape.y);
    ent.setPosition(x,y);
    buttons.push_back(Button(ent, textures[string{"./PNG's/"} + animName + string(".png")][0], field, animName));
}

float magnitude(sf::Vector2f a, sf::Vector2f b){
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

void Drawer::updateGui(int x, int y){
    sf::Vector2f pos((float)x,(float)y);
    for(int b_id=0;b_id<buttons.size(); b_id++){
        if(buttons[b_id].checkPress(pos)){
            for(int i=0; i<buttons.size(); i++) {if(i!=b_id) buttons[i].seleted=false;}
            stepUpdateButtons = true;
            buttons[b_id].press();
        }
    }
    if (magnitude(pos, shotButtonSp.getPosition()) <= shotButtonTexture.getSize().x*2){
        pistolEquipted = !pistolEquipted;
    }
}

void Drawer::addPlot(string trakingObj, Field* f, int x, int y, int w, int h){
    plot newplot(x, y, w, h, 100, trakingObj,f,trakingObj);
    plots.push_back(newplot);
}