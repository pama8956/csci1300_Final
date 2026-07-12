#ifndef NPC_H
#define NPC_H
#include "Character.h"
#include "Items.h"

class NPC : public Character{
    private:
    string dialouge;
    string requiredItem;
    int tradeCost;
    bool hasGivenItem;
    Item tradeItem;
    Item clueItem;

public :
    NPC(string n, string l, string d, string rI, int tc, Item tI, Item cI);

    void setDialouge(string d);
    string getDialouge();

    string getRequiredItem();
    int getCost();

    Item getTradeItem();
    Item getClueItem();

    bool getHasGivenItem();
    void markGiven();
};
#endif