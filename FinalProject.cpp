#include <iostream> 
#include <cmath>
#include <vector> 
#include <string>

#include "classes.h"
#include "functions.h"

using namespace std;


int main(){
    player p;
    string name;
    string objective;
    bool start;
    do{
    cout << "---Welcome to Vegas!---" << endl;
    cout << "Desk Worker: What is your name travler?" << endl << "Enter Name: " ;
    getline(cin,name);
    cout << "Nice to meet you, " << name << ". Here is your key card, dont loose it..." << endl ;
    cout << "You walk to your room, and go to the bathroom to get ready to meet your friend for a night out." << endl;
    cout << "You hear a knock on the door..." << endl << "Hello, " << name << " it's (Enter friends first name) ";
    cin >> objective;
    cout << "Let " << objective << " in to start the game" << endl << "Enter 1 to let in " << objective << ": " ;
    cin >> start; 
    cin.ignore();
    } while(start!=1);
    p.setName(name);
    cout << "Game started." << endl;
    getInterface(p);
}