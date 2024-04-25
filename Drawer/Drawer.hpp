#include "SFML/Graphics.hpp"
#include <vector>
#include <map>
#include <string>
#include "../Animals/Animals.hpp"
#include <chrono>
#include "../Field/Field.hpp"
#include "Button.hpp"
#include "plot.hpp"

class Drawer
{
private:
    sf::RenderWindow *window = nullptr;
    std::map<std::string,std::vector<sf::Texture>> textures;//текстуры животных
    std::map<std::string,std::vector<sf::Sprite>> entitySprites;//спрайты животных
    std::map<std::string,std::vector<sf::Sprite>> entitySpritesReverse;//отражённые спрайты животных
    int animationFPS = 5;//скорость анимации животных
    int deathAnimationDuration = 30000;//mcs but not correctly counting
    int64_t globalLastFrameTime = 0;
    float scalingFactor = 1;//модификатор размера объектов
    bool stepUpdateButtons = false;
    //загрузка текстур из файлов и создание спрайтов
    void loadTextures();
    //опрос кнопок
    void updateGui(int x,int y);
    std::vector<Button> buttons;
    sf::Texture backgroundTexture;
    sf::Sprite background;
    bool setFirstButton = true;

    int windowH;
    int windowW;

    //окружения и фунции распределения
    //функции распределения на вход принимают значениие шума Перлина, а на выход даёт количество деревьев или травы
    sf::Texture mapEnvTexture;
    std::vector<sf::Sprite> mapEnv;
    //создание леса по шуму перлина
    void mapGenerator(float frequency,double threashold, int octaves);
    int mapGenNVoxel = 10;

    int getNumberFromNoiseTrees(double noise_val){
        if(noise_val<=0.5) return 0;
        return 20 * (1-pow(noise_val+0.5,-5));
    }
    int getNumberFromNoiseGrass(double noise_val){
        return 50 * exp(-60*pow(abs(noise_val-0.65),2));
    }

    //пистолет
    float pistolScale = 0.4f; 
    sf::Texture pistolTexture;
    std::vector<sf::Sprite> pistolFrames;
    bool pistolEquipted = false;
    int pistolAnimFrame = -1; // -1 - нет анимации, 0 -> 4 и играет анимация, а потом опять присваивается -1
    int pistolAnimFPS = 10;
    int64_t pistolAnimLastFrameTime;
    float pistolMoveFactor = 50.0f;

    //кнопка стрельбы
    sf::Texture shotButtonTexture; 
    sf::Sprite shotButtonSp;
    sf::RectangleShape shotBtBg;
    float shotBtScale = 4;

    //параметры для кнопок
    int outlineBg = 5;
    sf::RectangleShape buttonBackround;

    //графики
    vector<plot> plots;
public:
    Drawer(int W,int H);
    Drawer(int W,int H, float scF);
    //добавит кнопку, которая будет создавать нужное животное
    void addSpawnButton(string animalName,Field *field,int x, int y, int w, int h);
    //добавит график, привязанный к объекту с именем trakingObj, по координатам и с заданым размером
    void addPlot(string trakingObj,Field *field, int x, int y, int w, int h); 
    //основная функция отрисовки всего
    void draw(vector<Animals*>);
    ~Drawer(){};
    vector<plot> getPlots();
};