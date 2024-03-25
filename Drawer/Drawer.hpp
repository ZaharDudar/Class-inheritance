#include "SFML/Graphics.hpp"
#include <vector>
#include <map>
#include <string>
#include "../Animals/Animals.hpp"
#include <chrono>
#include "../Field/Field.hpp"

class Button{
    protected:
        enum buttonType{
            NONE,
            SPAWNBUTTON,
            KILLBUTTON
        };
        std::string test;
        sf::Texture selfTexture;

        Field *field;
        string spawnArg;

        int selfType;
    public:
        bool seleted = false;
        sf::Sprite selfSprite;
        Button(sf::Sprite,sf::Texture);
        Button(sf::Sprite,sf::Texture, Field *field, string);
        bool checkPress(sf::Vector2f);
        // bool focused(sf::Vector2f);
        void press();
        void useOnMap(int x, int y);
};

class Drawer
{
private:
    sf::RenderWindow *window = nullptr;
    std::vector<int> a;
    std::map<std::string,std::vector<sf::Texture>> textures;
    std::map<std::string,std::vector<sf::Sprite>> entitySprites;
    std::map<std::string,std::vector<sf::Sprite>> entitySpritesReverse;
    int animationFPS = 5;
    int deathAnimationDuration = 30000;//mcs but not correctly counting
    int64_t globalLastFrameTime = 0;
    float scalingFactor = 1;
    bool stepUpdateButtons = false;
    void loadTextures();
    void updateGui(int x,int y);
    std::vector<Button> buttons;
    sf::Texture backgroundTexture;
    sf::Sprite background;
    bool setFirstButton = true;

    sf::Texture mapEnvTexture;
    std::vector<sf::Sprite> mapEnv;
    void mapGenerator(float frequency,double threashold, int octaves);
    int mapGenNVoxel = 10;
    int getNumberFromNoiseTrees(double noise_val){
        if(noise_val<=0.5) return 0;
        return 20 * (1-pow(noise_val+0.5,-5));
    }
    int getNumberFromNoiseGrass(double noise_val){
        return 50 * exp(-60*pow(abs(noise_val-0.65),2));
    }

    float pistolScale = 0.4f;
    sf::Texture pistolTexture;
    std::vector<sf::Sprite> pistolFrames;
    bool pistolEquipted = true;
    int pistolAnimFrame = -1; // -1 - нет анимации, 0 -> 4 и играет анимация, а потом опять присваивается -1
    int pistolAnimFPS = 10;
    int64_t pistolAnimLastFrameTime;
    float pistolMoveFactor = 50.0f;

    int outlineBg = 5;
    sf::RectangleShape buttonBackround;
public:
    Drawer(int W,int H);
    Drawer(int W,int H, float scF);
    //Добавить кнопку спавна
    void addSpawnButton(string animalName,Field *field,int x, int y, int w, int h);
    void draw(vector<Animals*>);
    ~Drawer(){};
};