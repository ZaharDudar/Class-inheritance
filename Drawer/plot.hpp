#pragma once
#include <string>
#include "../Animals/Animals.hpp"
#include <typeinfo>
#include "../Field/Field.hpp"

class plot{
    protected:
        int* data;
        sf::Vector2f pos;
        sf::Vector2f size;
        sf::RectangleShape bg;
        sf::Color bgColor = sf::Color(209, 206, 197);
        int currentValue;
        float updFrq=5;
        int64_t lastUpdate = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        size_t dataSize;
        int maxVal;
        Field *f;
        vector<Animals*> animals;
        std::string text;
        std::string trakingType;

        sf::Font font;
    public:
        plot(int x, int y, int h, int w, int dataSize, std::string text, Field *f, string trObjName);

        void update();
        void plotOnWin(sf::RenderWindow *w);
};

