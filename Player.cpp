#include "Player.h"

Player::Player(string n, int m) : Character(n, "Hotel") {  //Take player name and starting money
    money=m;
    actionsLeft = 5;
    actionsPerDay = 5;
    day = 1;
    maxDays = 3;
    cluesCollected = 0;
    travelingWithChow = false;
}

int Player::getMoney(){
    return money;
}
int Player::getDay(){
return day;
}
void Player::addMoney(int amount){
money+=amount;
}
bool Player::spendMoney(int amount){
if (amount<=money){
    money-=amount;
    return true;
} else {
    return false;
}
};


void Player::useAction(){
actionsLeft--;
};

int Player::getActionsRemaining(){
    return actionsLeft;
};

void Player::nextDay(){
    day++;
    actionsLeft=5;
}
void Player::moveLocation(string location){
    setLocation(location);
}
string Player::getCurrentLocation(){
    return getLocation();
}
void Player::addItem(Item i){
    inventory.push_back(i);
}
void Player::displayInventory(){
  for (int i = 0; i < (int)inventory.size(); i++){
        cout << inventory[i].getName() << " - " << inventory[i].getType() << endl;
    }
};
int Player::getClueCount(){
    return cluesCollected;
}
void Player::setTravelWithChow(bool b){
    travelingWithChow = b;
}
bool Player::isTravelingWithChow(){
    return travelingWithChow;
}
bool Player::checkWin(){
    if (cluesCollected >= 4){
        return true;
    }
    return false;
}
bool Player::checkLoss(){
    if (money <= 0){
        return true;
    }
    if (day > 3){
        return true;
    }
    return false;
}


