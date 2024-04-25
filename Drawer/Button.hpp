#include <string>
#include "../Field/Field.hpp"


class Button{ //класс кнопки для интерфейса
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
        bool checkPress(sf::Vector2f);//вернёт true если точка нажатия внутри кнопки
        // bool focused(sf::Vector2f);
        void press();//выполнить действие по нажатию
        void useOnMap(int x, int y);//действие на карте по конкретным координатам
};
