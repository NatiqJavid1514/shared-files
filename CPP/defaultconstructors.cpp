#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Player{
   private:
   int health;
   int xp;
   string name;
    public:
    void setname(string s1){
        name=s1;
    }
    string getname(){
        return name;
    }
    // Player(){
    //     name="bokachoda";
    //     xp=100;
    //     health=200;
    // }
    Player(string n,int xps,int healths){
        name=n;
        xp=xps;
        health=healths;

    }

};
int main(){
    Player a("Natiq",100,100)git add --all;
    // a.setname("NATS"); //without constructor//
    //default constructor//
    cout<<a.getname()<<endl;

    





}