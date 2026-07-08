#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include "classes.h"
using namespace std;

void getInterface(player p){
    cout << "===================================" << endl;
    cout << p.getName() << "'s Terminal" << endl; 
    cout << "===================================" << endl;
    cout << "Money: " << p.getMoney() << "$ "<< "     " << "Energy: " << "      "  ;
    cout << "Hour:" << p.getTime() << endl;
    displayMap("Casino", "Bar", "Hotel", "Alley", "Airport", p.getLocation());
}
#endif