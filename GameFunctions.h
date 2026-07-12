#ifndef GAMEFUNCTIONS_H
#define GAMEFUNCTIONS_H

#include "Location.h"
#include "Player.h"
#include "GameCharacters.h"
#include <vector>
#include <string>

void displayMap(Location loc1, Location loc2, Location loc3, Location loc4, Location loc5, string currentLocation);
int displayMenu(Player p, Location loc1, Location loc2, Location loc3, Location loc4, Location loc5, vector<NPC> npcs, NPC chow);
bool startSequence(Player p);
void endSequence(Location l, Player p);
void startGame();
Player loadPlayer(string filename);
vector<NPC> loadNPCs();
#endif