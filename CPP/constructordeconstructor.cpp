#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Player{
    private:
    int xp;
    int health;
    string name;

    public:
    void set_name(string s1){
        name=s1;
    }

    //constructors
    Player(string name,int health,int xp){
        cout<<"All set"<<endl;
    }
    Player(){
        cout<<"nothing set"<<endl;

    }
    Player(string name){
        cout<<"only name set"<<endl;
    }
    ~Player(){
        cout<<"Destructor called for "<<name<<endl;

    };


};
int main(){
    
    { 
        
       Player Natiq;
       Natiq.set_name("nats");
    }
    
    {
        Player Hero("Nats",100,5);
        Hero.set_name("Bangbang");
    }

    {Player *Nats=new Player("Natiq",100,200);
    Nats->set_name("bund");
delete Nats;} 
}