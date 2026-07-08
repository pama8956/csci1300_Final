#include "NPC.h"

NPC::NPC(string n, string d, bool c, string l) : Character(n, l){
    dialouge =d;
    hasClue=c;
}


void NPC::setClue(bool c){
    hasClue = c;
}
bool NPC::getHasClue(){
    return hasClue;
}

void NPC::setDialouge(string d){
    dialouge = d;
}
string NPC::getDialouge(){
    return dialouge;
}