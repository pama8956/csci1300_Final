#include "Items.h"
#include "Character.h"
#include <vector>
#include <string>
#include <iostream>

class Player : public Character{
private:
int money;
int actionsLeft;
int actionsPerDay;
int day;
int maxDays=3;
vector<Item> inventory;
int cluesCollected;
bool travelingWithChow;

public:
Player(string n, int m=500);
void addMoney(int amount);
bool spendMoney(int amount);
int getMoney();
void useAction();
int getActionsRemaining();
void nextDay();
int getDay();
void moveLocation(string location);
string getCurrentLocation();
void addItem(Item i);
void displayInventory();
int getClueCount();
void setTravelWithChow(bool b);
bool isTravelingWithChow(); 
bool checkWin();
bool checkLoss();
};

