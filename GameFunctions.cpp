#include "GameFunctions.h"
#include <fstream>

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
int displayMenu(Player p, Location loc1, Location loc2, Location loc3, Location loc4, Location loc5, vector<NPC> npcs, NPC chow){
    cout << endl;
    cout<< "============================================================"  << endl;
    cout<< "======================= Main Menu =========================="  << endl;
    cout<< "============================================================"  << endl;
    cout << "|| Player Name: " << p.getName() << endl;
    cout << "|| Day: " << p.getDay() << " / 3" << endl;
    cout << "|| Money: $" << p.getMoney() << endl;
    cout << "|| Energy Left: " << p.getActionsRemaining() << endl;
    cout << "|| Inventory: " ; 
    if(p.getInventoryCount() == 0){
        cout << "Inventory empty. ";
    }
    p.displayInventory();
    cout << endl;
    cout << "|| Clues Collected: " << p.getClueCount() << "/4" << endl;
    cout << endl;
    displayMap(loc1, loc2, loc3, loc4, loc5, p.getCurrentLocation());
    cout << endl;

    bool anyoneHere = false;
    cout << "Characters Nearby: " << endl;
    for (int i = 0; i < (int)npcs.size(); i++){
    if (npcs[i].getLocation() == p.getCurrentLocation()){
        cout << npcs[i].getName() << endl;
        anyoneHere = true;
        } 
    }
     if(chow.getLocation()==p.getCurrentLocation()){
        cout << chow.getName() << endl;
    }
    if(anyoneHere==0){
        cout << "Noone is at " << p.getCurrentLocation() << endl;
    }

    cout << endl;
    cout<< "========================= Action ==========================="  << endl;
    cout << endl;
    cout << "|| What would you like to do?" << endl;
    if(p.getLocation()==loc1.getName()){
        cout << "(Try moving around the map to find new characters)" << endl;
    } else if (p.getLocation()==loc2.getName()){
        cout << "(Try interacting with characters, or try your luck at the slots for some extra cash!)" << endl;
    } else if (p.getLocation()==loc4.getName()){
         cout << "(Have some fun and talk to people, you never know who might know something!)" << endl;
    } else if (p.getLocation()==loc5.getName()){
         cout << "(You've come a long way, try to find Alan, or Chow if youre looking for a good time...)" << endl;
    }
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

//print at start of game to give direction and initiate gameplay (introduction)
bool startSequence(Player p){
    cout << endl;
    cout<< "============================================================"  << endl;
    cout <<"============= Welcome to The Hangover the game =============" << endl;
    cout<< "============================================================"  << endl;
    cout << endl;
    cout << "You wake up to the sound of chirping birds..." << endl;
    cout << "You look around for your friend, but you cant seem to find him," << endl;
    cout << "Try going to the lobby..." << endl;
    cout << endl;
    bool goToLobby=0;
    cout << "Enter 1 to go to lobby, 0 to exit game" << endl;
    cin >> goToLobby;
    while (cin.fail() || (goToLobby!=0 && goToLobby!=1)){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input, enter 0 or 1." << endl;
        cout << "Enter 1 to go to lobby, 0 to exit game" << endl;
        cout << endl;
        cout << "Choice: ";
        cin >> goToLobby;
    }
    if (goToLobby==1){
        cout << endl;
        cout<< "============================================================"  << endl;
        cout << endl;
        cout << "You enter the lobby and go the the front desk." << endl;
        cout << endl;
        cout << "Hotel Worker says:" << endl;
        cout << "Hello, " << p.getName() << " you and your friend had quite a night!" << endl;
        cout << "You dont know where he is, do you? Want some help?" << endl;
        cout << endl;
        cout << "*Would you like to ask the desk worker for help?*" << endl;
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
            cout << endl;
            cout<< "============================================================"  << endl;
            cout << endl;
            cout << "Hotel Worker says:" << endl;
            cout << "Well, the first place you went to last night was The Casino, so you might want to head there and ask around for any clues..." << endl;
        } 
        else if(help==0){
            cout << endl;
            cout<< "============================================================"  << endl;
            cout << endl;
            cout << "Hotel Worker says:" << endl;
            cout << "Alright, hope you know what youre doing!! You guys went all around last night. " << endl;
        }
    }
    else if(goToLobby==0){
        cout << endl;
        cout<< "============================================================"  << endl;
        cout << "===================== Game aborted ========================" << endl;
        cout<< "============================================================"  << endl;
        return 0;
    }
    return 1;
}

//ending output wrap up game
void endSequence(Location l, Player p){
        cout << endl;
            cout << "=========================================================" << endl;
            cout << "=================== Congratulations =====================" << endl;
            cout << "=========================================================" << endl;
            cout << endl;
            cout << "You enter a mysterious car..." << endl;
            cout << "This better not be Chow again!" << endl; 
            cout << "..." << endl;
            cout << "You have arrived at the secret " << l.getName() << endl << "Congratulations " << p.getName() << "!" << endl;
            cout << endl;
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

//title screen and intro
void startGame(){
    cout << endl;
    cout<< "============================================================"  << endl;
    cout<< "===================== The Hangover ========================="  << endl;
    cout<< "============================================================"  << endl;
    cout << endl;
    cout << "Find your friend before you run out of time or money!" << endl;
    cout << "You have 3 days" << endl;
    cout << "Game Started, Good Luck!" << endl;
}

//player setup
Player loadPlayer(string filename){
    ifstream inFile(filename);
    string oldName;
    getline(inFile, oldName);
    int startingMoney;
    inFile >> startingMoney;
    inFile.close();

    string playerName;
    cout << "Enter your name: ";
    getline(cin, playerName);

    ofstream outFile(filename);
    outFile << playerName << endl;
    outFile << startingMoney << endl;
    outFile.close();

    Player player(playerName, startingMoney);
    return player;
}

//npc setup
vector<NPC> loadNPCs(){
    vector<NPC> npcs;
    npcs.push_back(Phil());
    npcs.push_back(Alan());
    npcs.push_back(Stu());
    npcs.push_back(Doug());
    return npcs;
}