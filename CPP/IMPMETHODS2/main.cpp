#include <iostream>
using namespace std;
#include "Account.h"
int main(){
Account nats;
nats.set_balance(10000.0);
nats.get_balance();
cout<<nats.get_balance();


}