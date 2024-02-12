#include <string>

class Food
{
protected:
    std::string name = "";
    bool meat;
public:
    Food(/* args */);
    bool isMeat() {return meat;};
    ~Food();
};

class Meat : public Food {
    public:
        Meat(std::string name){
            this->meat  = true;
            this->name = name;
        }
};
class Hearbs : public Food {
    public:
        Hearbs(std::string name){
            this->meat  = false;
            this->name = name;
        }
};