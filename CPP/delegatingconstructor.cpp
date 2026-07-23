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
 Player(string name_val="none",int hp_val=100,int xp_val=100);

 

};
Player::Player(string name_val,int hp_val,int xp_val): name{name_val},health{hp_val},xp{xp_val}{

 };

int main(){
    Player Natiq{"Natiq",};
    cout<<Natiq.get_health()<<endl;
}