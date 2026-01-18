#include <iostream>
using namespace std;

int main(){

    double average {0};
    int num1{0};
    int num2{0};
    int num3{0};
    int total_numbers {3};

    

    

    cout<< " Enter your first number: "<<endl;
    cin>>num1;
    cout<<" Enter your second number: "<<endl;
    cin>>num2;
    cout<<"Enter your third number: "<<endl;
    cin>>num3;
    

    cout<< "Average of your numbers is "<<static_cast<double>(num1+num2+num3)/total_numbers<<endl;

    return 0;






}