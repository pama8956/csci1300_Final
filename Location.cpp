#include "Location.h"


Location::Location(string n, int c, bool b){
    name=n;
    travelCost=c;
    unlocked =b;
}
    void Location::unlock(){
    unlocked = true;
    } //use to open unlocked location to players


    bool Location::isUnlocked(){ 
    return unlocked;
    }
    void Location::setName(string n){
        name =n;
    }
    string Location::getName(){
        return name;
    }
    
    void Location::setCost(int c){
        travelCost = c;
    }
    int Location::getCost(){
        return travelCost;
    }
