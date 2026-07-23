#include <iostream>
#include <vector>
#include <string>
using namespace std;
Sclass Player{
    string name;
    int xp;
    int health;

    public:
    int get_health(){
        return health;
    };
    int get_xp(){
        return xp;
    };
    string get_name(){
        return name;
    }
Player(string name_val="none",int hp_val=0,int xp_val=0);
    Player(const Player &source); //copy constructor
    ~Player(){
        cout<<"destructor is being called for: "<<name<<endl;
    }
   };
   Player::Player(string name_val,int hp_val,int xp_val): name{name_val},health{hp_val},xp{xp_val}{
    cout<<"3args constructor called for "<<name<<endl;}
   Player::Player(const Player &source):
name{source.name},health{source.health},xp{source.xp} {        // here we can use delegation as well 
    cout<<"copy constructor made of "<<source.name<<endl;}
void display_player(Player p){
    cout<<"Name: "<<p.get_name()<<endl;
    cout<<"xp: "<<p.get_xp()<<endl;
    cout<<"health: "<<p.get_health()<<endl;}
int main(){
    Player nats{"natiq",100,100};
    
    display_player(nats);
}