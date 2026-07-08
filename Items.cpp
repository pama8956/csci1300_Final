#include "Items.h"


Item::Item(string n, int v, string t, bool clue) {
    name = n;
    value = v;
    type = t;
    isClue = clue;
};

void Item::setName(string n){
    name=n;
}
string Item::getName(){
return name;
}

void Item::setType(string t){
    type=t;
}
string Item::getType(){
return type;
}

void Item::setValue(int v){
    value =v;
}
int Item::getValue(){
    return value;
}

void Item::setClue(bool clue){
    isClue=clue;

};

bool Item::getClue(){
    return isClue;
}