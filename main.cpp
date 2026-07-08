#include "Location.h"
#include <iostream>
#include <string>
using namespace std;


void displayMap(Location loc1, Location loc2, Location loc3, Location loc4, Location loc5, string currentLocation) {
    string l1;
    string l2;
    string l3;
    string l4;
    string l5;
   if( loc1.isUnlocked()==1){
     l1 = "[" + loc1.getName() + "]";
   } else{
      l1 = "[ ???? ]";
   }
    if( loc2.isUnlocked()==1){
         l2 = "[" + loc2.getName() + "]";
    }else{
      l2 = "[ ???? ]";
   }
    if( loc3.isUnlocked()==1){
         l3 = "[" + loc3.getName() + "]";
    }else{
      l3 = "[ ???? ]";
   }
    if( loc4.isUnlocked()==1){
         l4 = "[" + loc4.getName() + "]";
    }else{
      l4 = "[ ???? ]";
   }
    if( loc5.isUnlocked()==1){
         l5 = "[" + loc5.getName() + "]";
    }else{
      l5 = "[ ???? ]";
   }

    if (currentLocation == loc1.getName() && loc1.isUnlocked()==1){
      l5 = "[* ???? ]";}
    if (currentLocation == loc2.getName() && loc2.isUnlocked()==1) {
    l2 = "[*" + loc2.getName() + "]";
    }
    if (currentLocation == loc3.getName() && loc3.isUnlocked()==1) {
    l3 = "[*" + loc3.getName() + "]";
    }
    if (currentLocation == loc4.getName() && loc4.isUnlocked()==1) {
    l4 = "[*" + loc4.getName() + "]";
    }
    if (currentLocation == loc5.getName() && loc5.isUnlocked()==1){
     l5 = "[*" + loc5.getName() + "]";
    }
    cout << "=========|MAP|===========" << endl;
    cout << "                    " << l5 << endl;
    cout << "                         |" << endl;
    cout << "                         |  (far away)" << endl;
    cout << "                         |" << endl;
    cout << l1 << " ---- " << l2 << " ---- " << l3 << endl;
    cout << "                    |" << endl;
    cout << "                 " << l4 << endl;
    cout << endl;
    cout << "* = current location" << endl;
}

int displayMenu(Player p, Location loc1, Location loc2, Location loc3, Location loc4, Location loc5){
    cout<< "==============================="  << endl;
    cout << "|| Day: " << p.getDay() << " / 3" << endl;
    cout << "|| Money: $" << p.getMoney() << endl;
    cout << "|| Actions Left: " << p.getActionsRemaining() << endl;
    cout << endl;

    displayMap(loc1, loc2, loc3, loc4, loc5, p.getCurrentLocation());

    cout << endl;
    cout<< "===============================" << endl;
    cout << "|| What would you like to do?" << endl;
    cout << "|| 1. Move to another location" << endl;
    cout << "|| 2. Talk to someone" << endl;
    cout << "|| 3. View inventory" << endl;
    cout << "|| 4. View clues collected" << endl;
    cout << "|| 5. End day" << endl;

    cout << "Enter choice: ";
    int choice;
    cin >> choice;

    while (cin.fail() || choice < 1 || choice > 5){
        cin.clear();  
        cin.ignore(1000, '\n');
        cout << "Invalid choice, please enter a number 1-5: " << endl;
        cin >> choice;
    }
    return choice;
  }

int main(){
    Location loc1("Hotel", 25, 1);
    Location loc2("Casino", 75,1);
    Location loc3("The Porta Potty at The Park", 0,0);
    Location loc4("The Club", 150,1);
    Location loc5("Thailand", 50,1);

Player player("name",500);

while(player.getDay() <= 3 && !player.checkWin() && !player.checkLoss()){
int choice = displayMenu(player, loc1, loc2, loc3, loc4, loc5);

switch(choice){
    case 1: {
        cout << "Which location would you like to travel to?" << endl;
        cout << "Location: ";
        cin.ignore(1000, '\n');
        string destination;
        getline(cin, destination);
        while(destination!=loc1.getName() &&destination!=loc2.getName()&&destination!=loc3.getName()&&destination!=loc4.getName()&&destination!=loc5.getName()){
            cout<< "Invalid Location Name, please enter name exactly how written on map." << endl;
            cout << "Location: ";
            cin.ignore(100, '\n');
            getline(cin,destination);
        }
        int cost = 0;
    if (destination == loc1.getName()){
    cost = loc1.getCost();
    } else if (destination == loc2.getName()){
    cost = loc2.getCost();
    } else if (destination == loc3.getName()){
    cost = loc3.getCost();
    } else if (destination == loc4.getName()){
    cost = loc4.getCost();
    } else if (destination == loc5.getName()){
    cost = loc5.getCost();
    }
    if (player.spendMoney(cost)==1){
        player.moveLocation(destination);
        player.useAction();
        break;
    } else {
        cout << "You can't afford to travel there right now." << endl;
    }
        break; 
    }
    case 2:
    cout << "Characters available to interact with: " ;
    break;

    case 3:
    cout << "Print inventory";
    break;

    case 4:
    cout << "Clues collected: " << player.getClueCount();
    break;

    case 5:
    cout << "..";
    break;

    default:
    cout << "Invalid choice." << endl;
}
}
}
