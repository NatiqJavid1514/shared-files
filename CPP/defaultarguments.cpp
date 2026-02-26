#include <iostream>
#include <iomanip>
#include <string>


using namespace std;

double calc_cost(double base_cost,double tax,double shipping);
void greeting(string name,string prefix="Mr",string suffix="");

double calc_cost(double base_cost,double tax=0.06,double shipping=3.50){
    base_cost+=(base_cost*tax)+shipping;
    return base_cost;

}
void greeting(string name,string prefix,string suffix){
    cout<<"Hello "<<prefix+" "+name+" "+suffix<<endl;
    
}

int main(){
    double cost{};
    cost=calc_cost(100); // baaki default use karega//
    cost=calc_cost(100,0.08); // tax default abh use nahi hoga//
    cost=calc_cost(100,0.08,4.50);
    cout<<cost<<endl;
    greeting("nats","Engineer","Sahab");


    return 0;



}


