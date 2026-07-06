#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Account{
    public:
    int amount;
    int balance;
    int deposit;

    //methods
    string tosay(string x){
            cout<<x<<" is playing"<<endl;
    };

};
int main(){
    Account Nats;
   Nats.amount=1000;
   cout<<Nats.amount<<endl;
   Nats.tosay("Natiq");

   Account *frank=new Account;
   (*frank).amount=1000;

   cout<<(*frank).amount<<endl;

   cout<<frank->amount<<endl;

   frank->tosay("Bingchilling");
   

 

}