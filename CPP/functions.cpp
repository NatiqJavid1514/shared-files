#include <iostream>
#include <cmath>

using namespace std;
double num{};


int main(){
cout<<"Today we will apply predefined functions."<<endl;
cout<<"\n---------------------------------------------------"<<endl;
cout<<"Enter number: "<<endl;
cin>>num;

cout<<"Square root of "<<num<<" is "<<sqrt(num)<<endl;
cout<<"Cube root of "<<num<<" is "<<cbrt(num)<<endl;

cout<<"The sine of "<<num<<" is "<<sin(num)<<endl;

cout<<"The ceil of "<<num<<" is "<<ceil(num)<<endl; //next big integer

cout<<"The floor of "<<num<<" is "<<floor(num)<<endl; // previous integer

double power {};

cout<<"Enter a power to raise "<<num<<" to:";
cin>>power;
cout<<num<<" raised to the "<<power<<" is: "<<pow(num,power)<<endl;





}
