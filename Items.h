#include <iostream>
#include <string>

using namespace std;

class Item{
private:
    string name;
    int value=0;
    string type;
    bool isClue; 

public:

Item(string n, int v, string t, bool clue);

void setName(string n);

string getName();

void setType(string t);

string getType();

void setValue(int v);

int getValue();

void setClue(bool clue);

bool getClue();
};
