#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Player{
    string name;
    int xp;
    int health;

    public:
    int get_health(){
        return health;
    }
    //overloaded constructors
   
    Player(int h){
        health=h;
    }
    // Player(string n1,int x,int h){
    //     name=n1;
    //     xp=x;
    //     health=h;
    // }
    Player():name{"Natiq"},xp{10},health{20}{

    };
    Player(string n1,int h,int x):name{n1},xp{x},health{h}{};

};

int main(){
    Player natiq("natiq",20,30);git add --all
    cout<< natiq.get_health()<<endl;



}