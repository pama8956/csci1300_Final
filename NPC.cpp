#include "NPC.h"

  NPC::NPC(string n, string l, string d, string rI, int tc, Item tI, Item cI)
      : Character(n, l), tradeItem(tI), clueItem(cI){  dialouge = d;
    requiredItem = rI;
    tradeCost = tc;
    hasGivenItem = false;
}

    string NPC::getRequiredItem(){
        return requiredItem;
    }
    int NPC::getCost(){
        return tradeCost;
    }

    Item NPC::getTradeItem(){
    return tradeItem;
    }
  
    Item NPC::getClueItem(){
        return clueItem;
    }

    bool NPC::getHasGivenItem(){
        return hasGivenItem;
    }
    void NPC::markGiven(){
        hasGivenItem=true;
    }

    void NPC::setDialouge(string d){
    dialouge = d;
    }
    string NPC::getDialouge(){
    return dialouge;
    }