#include "Player.h"

class NPC : public Character{
    private:
    string dialouge;
    bool hasClue;
public :
    NPC(string n, string d, bool c, string l);
    void setClue(bool c);
    bool getHasClue();
    void setDialouge(string d);
    string getDialouge();

};