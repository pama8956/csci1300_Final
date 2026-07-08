#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string>
using namespace std;

class item {
    private:
    string name;
    string type;
    int value;
    bool winCondition;

    public:
    item(){}
    item(string nm, string tp, int val, bool wc){
        name =nm;
        type=tp;
        value=val;
        winCondition = wc;
    }
    string getName() { 
        return name; 
    }
    string getType() { 
        return type; 
    }
    int getValue() { 
        return value;
     }
    bool isWinCondition() {
         return winCondition; 
        }
    void displayItem() {
        cout << name << ": " << type << " " << value << "$" << endl;
    }
};

class player{

    private:
    string name;
    int money;
    int energy;
    string location;
    item inventory[8];
    int inventoryCount;
    int timeRemaining;

    public: 
    player(){
        inventoryCount =0;
    }

    int getTime(){
        return timeRemaining;
    }
    void setName(string input){
        name = input;
    }
    string getName() {
        return name;
    }

    bool spendMoney(int money, int spent){
        if(money>=spent){
            money-=spent;
            return true;
        
        
    } else {return false;}
}
    int getMoney() { 
        return money; 
    }
    void setMoney(int m) {
         money = m; 
    }
    void setEnergy(int e) {
         energy = e; 
        }
    int getEnergy() {
         return energy; 
        }
    void spendTime(int time){
        if(time>=7){
            cout << "Ran out of time, Game Over.";
        }
        time++;
    }
    };

class npc{
    private:
    string name;
    string role;
    string location;
    string dialouge;

    public:
    void setNPC(string n, string r, string loco, string dia){
        name = n;
        role = r;
        location=loco;
        dialouge=dia;
    }
    string getName() {
        return name;
    }
    string getRole(){
        return role;
    }
    string getLocation(){
        return location;
    }
    string getDialouge(){
        return dialouge;
    }

    void interaction(){
        cout << name << ": ";
        cout << dialouge << endl;
    }

    };


class location{
    private: 
    string name;
    int travelCost;

    public:
    void setName(string n){
        name =n;
    }
    string getName(){
        return name;
    }
    
    void setCost(int c){
        travelCost = c;
    }
    int getCost(){
        return travelCost;
    }  void displayMap(string loc1, string loc2, string loc3, string loc4, string loc5, string currentLocation) {
    string l1 = "[" + loc1 + "]";
    string l2 = "[" + loc2 + "]";
    string l3 = "[" + loc3 + "]";
    string l4 = "[" + loc4 + "]";
    string l5 = "[" + loc5 + "]";

    if (currentLocation == loc1) l1 = "[*" + loc1 + "]";
    if (currentLocation == loc2) l2 = "[*" + loc2 + "]";
    if (currentLocation == loc3) l3 = "[*" + loc3 + "]";
    if (currentLocation == loc4) l4 = "[*" + loc4 + "]";
    if (currentLocation == loc5) l5 = "[*" + loc5 + "]";

    cout << "                    " << l5 << endl;
    cout << "                         |" << endl;
    cout << "                         |  (far away)" << endl;
    cout << "                         |" << endl;
    cout << l1 << " ---- " << l2 << " ---- " << l3 << endl;
    cout << "                    |" << endl;
    cout << "                 " << l4 << endl;
    cout << endl;
    cout << "* = current location" << endl;
};

};
#endif