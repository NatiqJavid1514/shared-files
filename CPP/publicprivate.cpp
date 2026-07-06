#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Player{
    private:
    int xp;
    int health;
    string s1;

    public:
    void talk(string name){
        cout<<name<<"will beat "<<s1<<endl;

    }
};
int main(){
    Player a1;
    a1.talk("nats");





}