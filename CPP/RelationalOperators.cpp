#include <iostream>
using namespace std;

int main(){

    int num1{},num2{};

    cout<<boolalpha;

    // cout<<"Enter your numbers with spaces :"<<endl;
    // cin>>num1>>num2;

    // cout<<num1<<">"<<num2<<":"<<(num1>num2)<<endl;
    // cout<<num1<<">="<<num2<<":"<<(num1>=num2)<<endl;
    // cout<<num1<<"<"<<num2<<":"<<(num1<num2)<<endl;
    // cout<<num1<<"<="<<num2<<":"<<(num1<=num2)<<endl;
    const int lower{10};
    const int higher{20};

    cout<<"Enter an Integer greater than "<< lower<<endl;
    cin>>num1;
    cout<<num1<<">"<<lower<<" is "<<(num1>lower)<<endl;
    cout<<"Enter a number less or equal to "<<higher<<endl;
    cin>>num2;
    cout<<num2<<"<="<<higher<<" is "<<(num2<=higher)<<endl;




}