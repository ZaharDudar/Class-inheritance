#include <Animals.hpp>
class Elephant : public  Herbivores {
private:
bool Hobot;
public:
    Elephant() {
        this->Hobot = true;
    }
    void say();
};
