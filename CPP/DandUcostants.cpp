/* In this program we have to make an estimate displayer for cleaning company service
Charges:30$ per room
Sales tax 6%
Estimates are valid for 30 days

Provide the user for the number of rooms they would like to be cleaned and provide an estimate such as:

Estimate for carpet cleaning service:
Number of rooms:2
Price per room:$30
Cost:$60
Tax:3.6%

Total estimate: $63.6
This estimate is valid for 30days






*/
#include <iostream>


using namespace std;

int main(){

    int Number_of_rooms;
    int Price_per_room {30};
    float tax_rate {0.06};

    cout<<"Enter the number of rooms:"<<endl;
    cin>>Number_of_rooms;
    cout<<Number_of_rooms<<endl;
    cout<<"Price per room is $"<<Price_per_room<<endl;

    cout<<"Total cost:$"<<Number_of_rooms*Price_per_room<<endl;
    cout<<"Total tax:$"<<Number_of_rooms*Price_per_room*tax_rate<<endl;
    cout<<"Total estimated cost $:"<<(Number_of_rooms*Price_per_room)+(Number_of_rooms*Price_per_room*tax_rate)<<endl;
    cout<<"These estimates are valid for 30days only"<<endl;

    return 0;       






}