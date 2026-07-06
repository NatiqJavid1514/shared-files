#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Player{
    //attributes
    string name;
    int health;
    int xp;


    //methods
    void talk(string);
    bool is_dead();
};
int main(){
    Player hero;
    Player Frank;
    Player Nats;
    Player babi; //each one of them has xp health and name//
    //creating on heap//
    Player *enemy={nullptr};
    enemy=new Player;
    delete enemy;

    Player players[]{Frank,hero}; //array of players class//
    vector <Player> playervec{Frank,Nats};
    playervec.push_back(babi);






}