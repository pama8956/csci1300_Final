#include "Character.h"

Character::Character(string n, string l){
    name = n;
    location = l;
}

string Character::getName(){
    return name;
}
void Character::setName(string n){
    name = n;
} 
void Character::setLocation(string l){
    location = l;
}
string Character::getLocation(){
    return location;
}
    
