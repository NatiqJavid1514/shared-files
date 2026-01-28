#include <iostream>
using namespace std;
// i need to make a function which converts number of cents into classified dollars quaters dime nickel penny //
// 1 dollar = 100 cents 
// 1 quater = 25 cents 
// 1 dime = 10 cents 
// 1 nickel = 5 cents 
// 1 penny = 1 cent 
int amount{};
const int dollarincents{100};
 const int quatersincents{25};
 const int dimeincents{10};
 const int nickelincents{5};
const int pennyincents{1};
int dollars{};
int quaters{};
int dimes{};
int nickels{};
int pennies{};





int main()
{
    cout<<"Enter the amount you want to convert into change :"<<endl;
    cin>>amount;
    dollars=amount/100;
    quaters=(amount-(dollars*100))/25;
    dimes=(amount-((quaters*25)+(dollars*100)))/10;
    nickels=(amount-((quaters*25)+(dollars*100)+(dimes*10)))/5;
    pennies=(amount-((quaters*25)+(dollars*100)+(dimes*10)+(nickels*5)))/1;

    cout<<"Dollars: "<<dollars<<endl;
    cout<<"Quaters: "<<quaters<<endl;
    cout<<"Dimes: "<<dimes<<endl;
    cout<<"Nickles: "<<nickels<<endl;
    cout<<"Pennies: "<<pennies<<endl;

    
    

     











}