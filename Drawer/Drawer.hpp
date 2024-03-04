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
            SPAWNBUTTON
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
    float scalingFactor = 1;
    bool stepUpdateButtons = false;
    void loadTextures();
    void updateGui(int x,int y);
    std::vector<Button> buttons;
public:
    Drawer(int W,int H);
    Drawer(int W,int H, float scF);
    //Добавить кнопку спавна
    void addSpawnButton(string animalName,Field *field,int x, int y, int w, int h);
    void draw(vector<Animals*>);
    ~Drawer(){};
};