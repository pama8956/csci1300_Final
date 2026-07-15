# CSCI 1300 Final Project

## Theme: The Hangover (The Game)

### Play as the characters from your favorite move The Hangover as you try to find your lost friend. Travel around the map and interact with familiar characters to collect clues to find your lost friend. With only 3 days, players must spend budget wisely and trade with NPCS to reach the final hidden location.

## Goal

Collect 4 clues by buying and trading with characters around the map. Manage recources wisely to unlock secret location before time and money runs out. 

## How to compile and run

### Compile with this:
### g++ -std=c++17 Character.cpp Items.cpp Location.cpp Player.cpp NPC.cpp GameCharacters.cpp GameFunctions.cpp main.cpp -o game

Then run with ./game

## How to play

### Each day you get 5 actions. Traveling, playing games, and trading with characters all cost energy. When you run out, the day ends. You have 3 total days.

### Move locations, tlk to players, and sell items via the main menu. Look out for gambing at the casino, talking to Chow for a tradeoff in Thailand, and finding the secret location. Four characters have clues which you can buy or trade for, as well as hints for where to find the next clues. You can sell items when low on cash. Chow offers free travel, but you only get 3 turns a day instead of 5. 

## Classes

### Character: Base class with setters and getters for name and location

### Player: Inherits character, stores the user's money, energy, current day, inventory (a vector of Item objects), clue count, and whether they're traveling with Chow. Handles spending/earning money, adding/removing/selling items, day changes, and win/loss checks. (Bulkiest class)

### NPC: Inherits from character, stores character dialouge, the item they offer, clue they give, the item they need for a trade, price of their item, and if theyve been traded with.

###  Item: Stores item name, value, and type

### Location: Stores name travel cost, and if it is unlocked. 

#Function and character setup classes: These classes include long functions and character build to make main a cleaner file. 

## Extra credit

### NONE
