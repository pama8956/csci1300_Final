#include "NPC.h"
#include <string> 

class Location{
    private: 
    string name;
    int travelCost;
    bool unlocked;

    public:
    Location(string n, int c, bool u);

    void unlock();
    bool isUnlocked();

    void setName(string n);
    string getName();
    
    void setCost(int c);
    int getCost();
    
};