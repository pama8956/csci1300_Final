#include "GameFunctions.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//main function
int main(){

//setup
ifstream inFile("settings.txt"); //import starting settings
string oldName;
getline(inFile, oldName); //discard last save
int startingMoney;
inFile >> startingMoney; //read starting player name and money
inFile.close();
string playerName; 

//get player name, set and store name in settings file
cout << "Enter your name: ";
getline(cin, playerName);
ofstream outFile("settings.txt");
outFile << playerName << endl;  //write player name
outFile << startingMoney << endl; 
outFile.close(); 

Player player(playerName, startingMoney); //construct player

int spinCount=0; //set outside while loop to keep a running total used for gambling mechanic later. 

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

//end game if player terminates in start sequence, else continue
if(startSequence(player)==0){
return 0; 
}

startGame(); 

//main loop
while(player.getDay() <= 3 && !player.checkLoss()){
int choice = displayMenu(player, loc1, loc2, loc3, loc4, loc5, npcs, chow);

//choice logic
switch(choice){
    
    //location handling
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
   
    //character interaction
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

    cout << "Characters available to interact with: " << endl; 
        for (int i = 0; i < (int)hereNPCIndexes.size(); i++){
            int index = hereNPCIndexes[i];
            //number and print NPCs available at location
            cout << (i+1) << ". " << npcs[index].getName(); //index so choices start at 1 
            if (npcs[index].getHasGivenItem()){
            cout << " has nothing left to trade." << endl;
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
    
    bool atCasino = (player.getCurrentLocation() == "Casino"); //add gamble option if at casino
    int slotOption = maxOption + 1;
    if (atCasino){
    cout << slotOption << ". Talk to a dealer" << endl;
    maxOption = maxOption + 1;
    }

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
        cout << "Chow says: \n Whatever lame-o..." << endl;
        }
    }
    player.useAction(); 
    break;
} 

    //casino game option(gamble money)
if (player.getCurrentLocation() == "Casino" &&(who ==slotOption)){
        cout << endl;
        cout<< "============================================================"  << endl;
        cout << endl;
        cout << "Pete the dealer says: " << endl;
        cout << "Welcome to the Casino, would you like to play the slot machine?" << endl;
        cout << endl;
        cout << "Enter a 1 to play, 0 to exit: " ;
        bool playSlots;
        cin >>playSlots;
        while(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "invalid input, enter a 0 or 1: ";
            cin >>playSlots;
        }
        if(playSlots==1){
            
    cout << "How much would you like to bet? (0 to cancel)" << endl;
    cout << "Bet: ";
    int bet;
    cin >> bet;
    while (cin.fail() || bet < 0 || bet > player.getMoney()){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Budget: " << player.getMoney() << endl;
        cout << "Enter a valid bet within your budget or 0 to cancel: " << endl;
        cin >> bet;
    } 
    if (bet==0){
        cout << endl;
        cout<< "============================================================"  << endl;
        cout << endl;
        cout << "Scared money dont make money, maybe next time ;)" << endl;
        break;
        }
     else{ 
        player.spendMoney(bet);
        spinCount++;
        int randomGenerator = ((player.getMoney()/3 + spinCount*7 + player.getDay()*2+player.getActionsRemaining())%5); //bunch of changing variables generates semi random number with 5 possible outputs
        if (player.isTravelingWithChow()==1){ //better odds if traveling with chow (50/50) BUT lower largest payout possible
            if(randomGenerator==1 ||randomGenerator==2 || randomGenerator==3){
                int winnings = bet*2;
                cout << endl;
                cout<< "============================================================"  << endl;
                cout << endl;
                cout << "Winner!!!" << endl;
                player.addMoney(winnings);
                cout << "Winnings: $" << winnings << endl;
            } else{
            cout << endl;
            cout<< "============================================================"  << endl;
            cout << endl;
            cout << "Bust, better luck next time." << endl;
            cout << "You lost: $" << bet << endl;
            }
        }
        else if (randomGenerator==0){
            int winnings = bet*3;
            cout << endl;
            cout<< "============================================================"  << endl;
            cout << endl;
            cout << "JACKPOT!!" << endl;
            player.addMoney(winnings);
            cout << "Winnings: $" << winnings << endl;

        } else if (randomGenerator==1){
            int winnings = bet*2;
            cout << endl;
            cout<< "============================================================"  << endl;
            cout << endl;
            cout << "Hit!!" << endl;
            player.addMoney(winnings);
            cout << "Winnings: $" << winnings << endl;
        }
        else if (randomGenerator==3){
            int winnings = bet;
            cout << endl;
            cout<< "============================================================"  << endl;
            cout << endl;
            cout << "Broke even" << endl;
            player.addMoney(winnings);
            cout << "Winnings: $" << winnings << endl;
        } 
        else{
            cout << endl;
            cout<< "============================================================"  << endl;
            cout << endl;
            cout << "BUST, better luck next time." << endl;
            cout << "You lost: $" << bet << endl;
            }
        player.useAction();
        }
    }
    break;
}

    //normal case(No chow)
else{
    int index = hereNPCIndexes[who-1]; //back to zero index
        //print character dialouge
    cout << endl;
    cout<< "============================================================"  << endl;
    cout << endl;
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
                cout << endl;
                cout<< "============================================================"  << endl;
                cout << endl;
                cout << "Purchase successful. You now have " << npcs[index].getTradeItem().getName() << endl;
                cout << "Spent " << npcs[index].getCost() << endl;
                player.addItem(npcs[index].getTradeItem()); //adds new trade item
                player.addItem(npcs[index].getClueItem()); // adds clue item 
                npcs[index].markGiven(); //tracks that npc has already traded

                if (npcs[index].getName() == "Phil"){
                    cout << endl;
                    cout<< "============================================================"  << endl;
                    cout << endl;
                    cout << "Phil whispers: Take those pictures to Alan, he might know something. I heard he's somewhere overseas partying with Chow..." << endl;
                } else if (npcs[index].getName() == "Alan"){
                   cout << endl;
                    cout<< "============================================================"  << endl;
                    cout << endl; 
                   cout << "Alan laughs: Stu back at The Club will want this." << endl;
                } else if (npcs[index].getName() == "Stu"){
                    cout << endl;
                    cout<< "============================================================"  << endl;
                    cout << endl;
                    cout << "Stu says: Doug's around here somewhere at The Club, go find him." << endl;
                } else if (npcs[index].getName() == "Doug"){
                    cout << endl;
                    cout<< "============================================================"  << endl;
                    cout << endl;
                cout << "Doug says: Good luck finding your friend, hope this helps." << endl;
                }
                    if (player.getClueCount() >= 4){
                        loc3.unlock();
                    }
            } else{ //if player cant afford
                    cout << endl;
                    cout<< "============================================================"  << endl;
                    cout << endl;
                    cout << "Not enought Money." << endl;
                break;
            }
        }
        else if(tradeChoice==2){
            if(canTrade==0){ 
                    cout << endl;
                    cout<< "============================================================"  << endl;
                    cout << endl;
                cout << "Cannot trade with " << npcs[index].getName() << " right now." << endl; //if you dont have items or item already been traded 
                break;
            }
            //same logic as buying, removes item instead of money
                    cout << endl;
                    cout<< "============================================================"  << endl;
                    cout << endl;
            cout << "Trade successful. You now have " << npcs[index].getTradeItem().getName() << endl;
            player.removeItem(npcs[index].getRequiredItem()); 
            player.addItem(npcs[index].getTradeItem());
            player.addItem(npcs[index].getClueItem());
            npcs[index].markGiven();
            if (player.getClueCount() >= 4){ //tells player that all clues have been collected
                loc3.unlock();
                if(player.getActionsRemaining() <= 0){
            player.addAction(); //adds final action if player used last action to get final clue
            } 
                cout << endl;
                cout << endl << "Something about that last piece makes everything click into place..." << endl;
                cout << "A new path has opened up. Time to go find your friend." << endl << "Clues collected: 4/4" << endl;
                cout << endl;
            } else if (npcs[index].getName() == "Phil"){
                    cout << endl;
                    cout<< "============================================================"  << endl;
                    cout << endl;
                    cout << "Phil whispers: Take those pictures to Alan, he might know something. I heard he's somewhere overseas partying with Chow..." << endl;
                } else if (npcs[index].getName() == "Alan"){
                   cout << endl;
                    cout<< "============================================================"  << endl;
                    cout << endl; 
                   cout << "Alan laughs: Stu back at The Club will want this." << endl;
                } else if (npcs[index].getName() == "Stu"){
                    cout << endl;
                    cout<< "============================================================"  << endl;
                    cout << endl;
                    cout << "Stu says: Doug's around here somewhere at The Club, go find him." << endl;
                } else if (npcs[index].getName() == "Doug"){
                    cout << endl;
                    cout<< "============================================================"  << endl;
                    cout << endl;
                cout << "Doug says: Good luck finding your friend, hope this helps." << endl;
                }
                    if (player.getClueCount() >= 4){
                        loc3.unlock();
                    }
            
        } else{
            break;
        }
        player.useAction();
    }
    cout << endl;
    break;
    
}
    } //end case 1 bracket

    //sell logic
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
    
    //self initiated terminate game   
    case 4: {
    cout << endl;
    cout << "=======GAME OVER======" << endl;
    return 0;
    cout << endl;
    break;
    }
    
    //invalid input handling
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
    cout << endl << "Time or money ran out. Your friend is lost forever..." << endl;
    cout << "OH WELL" << endl;
}
}
}

