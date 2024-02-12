#include <string>

using namespace std;

class Animals
{
protected:
    int legs;
    int n_food=0;
    string* food = {};
public:
    virtual Animals(/* args */);
    string* getFoodList(){
        string* tmp = new string[n_food];
        for(int i=0; i<n_food;i++){
            tmp[i]=food[i];
        }
        return tmp;
    }
    ~Animals();
};

