#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string> 

using namespace std;

class Character{

    private:
    string name;
    string location;

    public:

    Character(string n, string l);
    string getName();
    void setName(string n);
    string getLocation();
    void setLocation(string l);

};
#endif