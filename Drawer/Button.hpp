#include <string>
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
