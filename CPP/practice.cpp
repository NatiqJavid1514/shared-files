#include <iostream>
using namespace std;
int main(){
   int num{};
   cout<<"Enter your number: "<<endl;
   cin>>num;
   int product{1};
   int remainder{};


while(num!=0){
    if(num>0)
    remainder=num%10;
    product*=remainder;
    num=num/10;
}
cout<<product;
}
    
