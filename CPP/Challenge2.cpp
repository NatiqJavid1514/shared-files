/* In this program we have to make an estimate displayer for cleaning company service
Charges for small room:$25
Charges for Large room:$35
Sales tax 6%
Estimates are valid for 30 days

Provide the user for the number of rooms they would like to be cleaned and provide an estimate such as:

Estimate for carpet cleaning service:
Number of small rooms:1
Number of large rooms:1
Price per large room:$35
Price per small room:$25
Cost:$60
Tax:$3.6

Total estimate: $63.6
This estimate is valid for 30days*/

#include <iostream>

using namespace std;

int main(){

    int number_of_small_rooms;


    int number_of_large_rooms;
    int price_for_large_room {35};
    int price_for_small_room {25};
    float tax_rate {0.06};

    cout<<" Welcome to Nats cleaning services"<<endl;
    cout<<"Please enter number of large rooms to clean:"<<endl;
    cin>>number_of_large_rooms;
    cout<<"Please enter number of small rooms to clean:"<<endl;
    cin>>number_of_small_rooms;
    cout<<"Number of Large rooms:"<<number_of_large_rooms<<endl;
    cout<<"Price for Large room: $"<<price_for_large_room<<endl;
    cout<<"Number of Small rooms:"<<number_of_small_rooms<<endl;
    cout<<"Price for small room: $"<<price_for_small_room<<endl;
    cout<<"Total cost: $"<<(number_of_large_rooms*price_for_large_room)+(number_of_small_rooms*price_for_small_room)<<endl;
    cout<<"Total tax: $"<<((number_of_large_rooms*price_for_large_room)+(number_of_small_rooms*price_for_small_room))*tax_rate<<endl;
    cout<<"Total Estimate: $"<<(number_of_large_rooms*price_for_large_room)+(number_of_small_rooms*price_for_small_room)+((number_of_large_rooms*price_for_large_room)+(number_of_small_rooms*price_for_small_room))*tax_rate<<endl;

    cout<<"These estimates are valid only for 30 days";

    return 0;
}

