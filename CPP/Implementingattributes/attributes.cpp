#include <iostream>
using namespace std;
#include <string>
#include <vector>
class Player{
    private:
    int xp;
    int health; 
    string name;

    public:
    void set_name(string s1);
    void talk(string s1);
};
class Account{
    private:
    double balance;

    public:
    void set_balance(double bal){
        balance=bal;
    }
    bool deposit(double amount){       //inside class declaration
        balance=balance+amount;
        return true;
    }
    bool withdraw(double amount){
        balance=balance-amount;
        return true;
    }
};
void Player::set_name(string s1){
    name=s1;
};
void Player::talk(string s1){
    cout<<s1<<"is with "<<name<<endl;
}
int main(){
 Player Bats;
 Account Nats;
 Bats.set_name("Wats");
 Bats.talk("Rats");





}