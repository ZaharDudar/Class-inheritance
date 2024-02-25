#include "SFML/Graphics.hpp"
#include <vector>
#include <map>
#include <string>
#include "../Animals/Animals.hpp"
#include <chrono>


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
    void loadTextures();
public:
    Drawer(int W,int H);
    Drawer(int W,int H, float scF);
    void draw(vector<Animals*>);
    ~Drawer(){};
};