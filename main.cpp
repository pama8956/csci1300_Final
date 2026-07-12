#include "Location.h"
#include "Player.h"
#include "GameCharacters.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//set locations to a simple map, show current location and location names
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
    l1 = "[*" + loc1.getName() + "]";
    }
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
    cout << "========================== Map ============================="  << endl;
    cout << endl;
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

////show menu and ask for next move
int displayMenu(Player p, Location loc1, Location loc2, Location loc3, Location loc4, Location loc5){
    cout << endl;
    cout<< "============================================================"  << endl;
    cout<< "======================= Main Menu =========================="  << endl;
    cout<< "============================================================"  << endl;
    cout << "|| Player Name: " << p.getName() << endl;
    cout << "|| Day: " << p.getDay() << " / 3" << endl;
    cout << "|| Money: $" << p.getMoney() << endl;
    cout << "|| Energy Left: " << p.getActionsRemaining() << endl;
    cout << "|| Inventory: " << endl; 
    if(p.getInventoryCount() == 0){
        cout << "Inventory empty. " << endl;
    }
    p.displayInventory();
    cout << "|| Clues Collected: " << p.getClueCount() << endl;
    cout << endl;
    displayMap(loc1, loc2, loc3, loc4, loc5, p.getCurrentLocation());

    cout << endl;
    cout<< "========================= Action ==========================="  << endl;
    cout << endl;
    cout << "|| What would you like to do?" << endl;
    cout << "|| 1. Move to another location" << endl;
    cout << "|| 2. Talk to someone" << endl;
    cout << "|| 3. Sell items" << endl;
    cout << "|| 4. End game" << endl;
    cout << "Enter choice: ";
    int choice;
    cin >> choice;

    while (cin.fail() || choice < 1 || choice > 4){
        cin.clear();  
        cin.ignore(1000, '\n');
        cout << "Invalid choice, please enter a number 1-4: " << endl;
        cin >> choice;
    }
    return choice;
  }

//print at start of game to give direction
bool startSequence(Player p){
    cout << "=======Welcome to The Hangover the game=========" << endl;
    cout << "You wake up to the sound of chirping birds..." << endl;
    cout << "You look around for your friend, but you cant seem to find him," << endl;
    cout << "Try going to the lobby..." << endl;
    bool goToLobby=0;
    cout << "Enter 1 to go to lobby, 0 to exit game" << endl;
    cin >> goToLobby;
    while (cin.fail() || (goToLobby!=0 && goToLobby!=1)){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input, enter 0 or 1." << endl;
        cout << "Enter 1 to go to lobby, 0 to exit game" << endl;
        cout << "Choice: ";
        cin >> goToLobby;
    }
    if (goToLobby==1){
        cout << "You enter the lobby and go the the front desk." << endl;
        cout << "Hotel Worker says:" << endl;
        cout << "Hello, " << p.getName() << " you and your friend had quite a night! You dont know where he is do you? Need some help?" << endl;
        cout << "Would you like to ask the desk worker for help? " << endl;
        bool help;
        cout << "Enter a 1 to ask for help, 0 to decline." << endl;
        cin >> help;
          while (cin.fail() || (help!=0 && help!=1)){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input, enter 0 or 1." << endl;
            cout << "Enter a 1 to ask for help, 0 to decline." << endl;
            cout << "Choice: ";
            cin >> help;
          }
        if(help==1){
            cout << "Hotel Worker says:" << endl;
            cout << "First place you went to last night was The Casino, you might want to head there and start retracing your steps..." << endl;
        } 
        else if(help==0){
            cout << "Hotel Worker says:" << endl;
            cout << "Alright, hope you know what youre doing!! You guys went all around last night. " << endl;
        }
    }
    else if(goToLobby==0){
        cout << "Game aborted" << endl;
        return 0;
    }
    return 1;
}

//ending output wrap up game
void endSequence(Location l, Player p){
        cout << endl;
            cout << "=========================================================" << endl;
            cout << "You enter a mysterious car..." << endl;
            cout << "This better not be Chow again!" << endl; 
            cout << "You have arrived at the secret " << l.getName() << endl << "Congratulations " << p.getName() << "!" << endl;
            cout << "You begin to walk around and notice a trail of cigarette ash and beer cans leading the the porta potty. " << endl;
            cout << "*Groan* " << endl; 
            cout << "*Arggg* " << endl; 
            cout << "Oh nooo" << endl;
            cout << "*SLAM* " << endl; 
            cout << "You open the door to see your friend strung across the floor. " << endl; 
            cout << "*GASP* " << p.getName() << " Its you!!" << endl; 
            cout << "You found me! Ive been stuck in here for " << (p.getDay()) << " days!" << endl; 
            cout << "What the hell happened??" << endl; 
            cout << "..." << endl; 
            cout << "Congratulations, you have beat: The Hangover--THE GAME!!!" << endl;
            cout << "Thanks for playing, hopefully this doesnt happen again..." << endl;
            cout << "Created by Patrick Martin ;)" << endl; 
            cout << "=========================================================" << endl;
}


//setup and gameloop
int main(){

ifstream inFile("settings.txt"); //import starting settings
string oldName;
getline(inFile, oldName); //discard last save
int startingMoney;
inFile >> startingMoney;
inFile.close();

string playerName; //set and store player name in settings file

cout << "Enter your name: ";
getline(cin, playerName);
ofstream outFile("settings.txt");
outFile << playerName << endl;
outFile << startingMoney << endl;
outFile.close();

Player player(playerName, startingMoney); //construct player

vector<NPC> npcs; //add NPCs
npcs.push_back(Phil());
npcs.push_back(Alan());
npcs.push_back(Stu());
npcs.push_back(Doug());
NPC chow = Chow();

//set map locations
Location loc1("Hotel", 25, 1);
Location loc2("Casino", 75,1);
Location loc3("The Porta Potty at The Park", 0,0);
Location loc4("The Club", 150,1);
Location loc5("Thailand", 50,1);

//start game
if(startSequence(player)==0){
return 0;
}
    cout << endl;
    cout << "Game Started, Good Luck!" << endl;
    cout << endl;
//main loop
while(player.getDay() <= 3 && !player.checkLoss()){
int choice = displayMenu(player, loc1, loc2, loc3, loc4, loc5);

//choice logic
switch(choice){
    case 1: {
        cout << endl;
        cout << "Which location would you like to travel to?" << endl;
        cout << "Location: ";
        cin.ignore(1000, '\n');
        string destination;
        getline(cin, destination); //get location and input validation
        while(destination!=loc1.getName() && destination!=loc2.getName()&&destination!=loc3.getName()&&destination!=loc4.getName()&&destination!=loc5.getName()){
            cout<< "Invalid Location Name, please enter name exactly how written on map." << endl;
            cout << "Location: ";
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
    if (player.isTravelingWithChow()==1){
    cost = 0;
    }   
    if (destination == loc3.getName() && !loc3.isUnlocked()){
        cout << "Location hidden, continue collecting clues to unlock." << endl;
        break;
    }
    if (player.spendMoney(cost)==1){
        player.moveLocation(destination);
        if (destination == loc1.getName()){
            cout << "Purchased a train ticket to the Hotel..." << endl;
            cout << "Man am I tired!" << endl; 
            cout << "You have arrived at the Hotel." << endl;
        } else if (destination == loc2.getName()){
            cout << "Catching a taxi to the Casino..." << endl;
            cout << "Hope youre feeling lucky!" << endl; 
            cout << "You have arrived at the Casino." << endl;
        } else if (destination == loc3.getName()){
            endSequence(loc3,player);
            return 0;
        } else if (destination == loc4.getName()){
            cout << "Stumbling towards the Club..." << endl;
            cout << "LETSS PARTY!!" << endl; 
            cout << "You have arrived at the Club." << endl;
        } else if (destination == loc5.getName()){
            cout << "Catching a jet to Thailand!!!" << endl;
            cout << "Man this is a long flight, hope you brought an energy drink..." << endl; 
            cout << "You have arrived at Thailand, look out for Chow!" << endl;
        }
        player.useAction();
        break;
    } else {
        cout << "You can't afford to travel there right now." << endl;
    }
        break; 
    }
    case 2:{
    vector<int> hereNPCIndexes;
    cout << endl;
    for (int i=0; i<(int)npcs.size();i++){
         if (npcs[i].getLocation() == player.getCurrentLocation()){
            hereNPCIndexes.push_back(i);
        }
    }
    
    bool chowHere = (chow.getLocation() == player.getCurrentLocation()); //only applys for hotel, no characters, no one to interact with. 
      if (hereNPCIndexes.size() == 0 && !chowHere){
        cout << "There's no one here to talk to. Move locations to find new characters." << endl;
        break;
    }

    cout << "Characters available to interact with: " ; 
        for (int i = 0; i < (int)hereNPCIndexes.size(); i++){
            int index = hereNPCIndexes[i];
            //number and print NPCs available at location
            cout << (i+1) << ". " << npcs[index].getName(); //index so choices start at 1 
            if (npcs[index].getHasGivenItem()){
            cout << npcs[index].getName() << " has nothing left to trade." << endl;
            }
            else {
            cout << " offers " << npcs[index].getTradeItem().getName() << endl; //shows NPCS and what they have to trade
        }
    }
 //chow logic, only applies in thailand
             if (chowHere){
        cout << ((int)hereNPCIndexes.size() + 1) << ". " << chow.getName() << " offers a ride" << endl; //add chow to list of NPCS,
             }

    int maxOption = (int)hereNPCIndexes.size(); //choices for npc interaction
        if (chowHere){
         maxOption = maxOption + 1;
        }

    int chowOption = (int)hereNPCIndexes.size() + 1; //add chow option
    //enter choice number
    cout << "Enter choice: ";
    int who;
    cin>> who;
    while(cin.fail() || who < 1 || who > maxOption){ //input validation
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid choice, try again: ";
    cin >> who;
    }
    if (chowHere && who == chowOption){
        if(player.isTravelingWithChow()==true){
            cout<< "Already traveling with chow" << endl;
            break;
        }//cant double down
        else{
    cout << chow.getDialouge() << endl;
    int chowChoice;
    cout << "Enter a 1 to travel with Chow or a 0 to continue without him." << endl << "Choice: ";
    cin>> chowChoice;
    while(cin.fail() || (chowChoice !=1 && chowChoice !=0)){
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid choice, try again: ";
    cin >> chowChoice;
    }
    if(chowChoice==1){
        player.setTravelWithChow(true);
        cout << "Now traveling with Chow." << endl;
        cout << "Traveling cost is now free, but now you only get 3 energy per day. Good luck!" << endl;
    } else{
        cout << "Not traveling with Chow." << endl;
        cout << "Chow says: Whatever lame-o..." << endl;
    }
    }
    player.useAction(); 
    } 

    //normal case(No chow)
    else{
    int index = hereNPCIndexes[who-1]; //back to zero index
        //print character dialouge
    cout << endl << npcs[index].getName() << " says:" << endl;
    cout << "\"" << npcs[index].getDialouge() << "\"" << endl ;
    cout << endl; 

    if (npcs[index].getHasGivenItem()){
        cout << " has nothing left for you." << endl; //cant trade if NPC already has item
    } else {
        bool canTrade = (npcs[index].getRequiredItem() != "NONE" && player.hasItem(npcs[index].getRequiredItem())); //sets NPC ready to trade if player has an item to trade and player has the required item
    
        cout << "1. Buy " << npcs[index].getTradeItem().getName() << " for $" << npcs[index].getCost() << endl; //buy option
        if (canTrade){
            cout << "2. Trade your " << npcs[index].getRequiredItem() << " (free)" << endl; //trade option if valid
        }
        cout << "3. Leave" << endl;
        cout << "Enter choice: ";

        int tradeChoice;
        cin >> tradeChoice;
        while (cin.fail() || tradeChoice < 1 || tradeChoice > 3){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid choice, please enter 1-3: ";
            cin >> tradeChoice;
        }

        if(tradeChoice==1){ //adds item to inventory, shows what you purchased and for how much
            if(player.spendMoney(npcs[index].getCost())==1){
                cout << "Purchase successful. You now have " << npcs[index].getTradeItem().getName() << endl;
                cout << "Spent " << npcs[index].getCost() << endl;
                player.addItem(npcs[index].getTradeItem()); //adds new trade item
                player.addItem(npcs[index].getClueItem()); // adds clue item 
                npcs[index].markGiven(); //tracks that npc has already traded
                 if (player.getClueCount() >= 4){
                loc3.unlock();
                
                }
            } else{ //if player cant afford
                cout << "Not enought Money." << endl;
                break;
            }
        }
        else if(tradeChoice==2){
            if(canTrade==0){ 
                cout << "Cannot trade with " << npcs[index].getName() << " right now." << endl; //if you dont have items or item already been traded 
                break;
            }
            //same logic as buying, removes item instead of money
            cout << "Trade successful. You now have " << npcs[index].getTradeItem().getName() << endl;
            player.removeItem(npcs[index].getRequiredItem()); 
            player.addItem(npcs[index].getTradeItem());
            player.addItem(npcs[index].getClueItem());
            npcs[index].markGiven();
            if (player.getClueCount() >= 4){ //tells player that all clues have been collected
                loc3.unlock();
                cout << endl;
                cout << endl << "Something about that last piece makes everything click into place..." << endl;
                cout << "A new path has opened up. Time to go find your friend." << endl << "Clues collected: 4/4" << endl;
                cout << endl;
            }
        } else{
            break;
        }
        player.useAction();
    }
    cout << endl;
    break;
    
}
    }
    case 3:{
    cout << endl;
    cout << "Items available to sell: ";
    player.displayInventory();
    cout << endl << "Enter the exact name of an item to sell or type cancel: ";
    cin.ignore(1000, '\n');
    string item;
    getline(cin, item);
    while(player.hasItem(item)!=1 && item != "cancel"){
        cout << "Error, not an item. Copy item exact name." << endl;
        cout << "Item to sell: ";
        getline(cin, item);
    }
    if(item == "cancel"){
        cout << "Back to menu..." << endl;
        cout << endl;
        break;
    }
    int value = player.getItemValue(item);

    if(player.sellItem(item)==1){
        cout << "Sold " << item << " for " << value << "$" << endl;
    }
    cout << endl;
    break;
    }
    case 4: {
    cout << endl;
    cout << "=======GAME OVER======" << endl;
    return 0;
    cout << endl;
    break;
    }
    default:{
    cout << endl;
    cout << "Invalid choice." << endl;
    cout << endl;
    break; }
}
//End of action checks(check for new day, check for loss conditions)
if (player.getActionsRemaining() <= 0){
    cout << endl;
    cout << endl << "You're out of energy for today. Resting until tomorrow..." << endl;
    cout << endl;
    player.nextDay();
}
if (player.checkLoss()){
    cout << endl << "Time or money ran out. Your friend is lost forever." << endl;
}
}
}

