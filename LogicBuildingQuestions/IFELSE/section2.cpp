#include <iostream>
#include <string>
using namespace std;
int main(){
//     int x,temp,rem,a,b,c;
//     cout<<"Enter number to check if digits are distinct: "<<endl;
//     cin>>x;
//     while(x!=0){
//         rem=x%10;
//         a=rem;
//         x=x/10;
//         break;

//     }
//     while(x!=0){
//         rem=x%10;
//         b=rem;
//         x=x/10;
//         break;
//     }
//     while(x!=0){
//         rem=x%10;
//         c=rem;
//         x=x/10;
//     }
// cout<<a<<" "<<b<<" "<<c<<endl;   //my method aik aik karke digit extract karo general method is in dc chat;

//check if first and last digit of a 4 digit number is same

// int x,a,b,c,d;
// cout<<"Enter 4-digit number: "<<endl;
// cin>>x;
// a=x/1000;
// b=(x/100)%10;
// c=(x/10)%10;
// d=x%10;

// if(a==d){
//     cout<<"first and last digits are equal"<<endl;

// }
// else{
//     cout<<"not equal"<<endl;

// }



//check whether a number is single digit,double digit or multiple digit;
// int a,count=0;
// cout<<"Enter your number"<<endl;
// cin>>a;
// while(a!=0){
//     a=a/10;
//     count++;
// }
// if(count==1){
//     cout<<"single digit number"<<endl;

// }
// else if(count==2){
//     cout<<"double digit number"<<endl;
// }
// else{
//     cout<<"multi digit number"<<endl;
// }


//check if an amount can be divided into 2000,500 and 100 currency notes;
// int amount,twothousand,fivehundred,hundred;
// cout<<"Enter amount: "<<endl;
// cin>>amount;
// twothousand=amount/2000;
// fivehundred=(amount-(twothousand*2000))/500;
// hundred=(amount-(twothousand*2000+fivehundred*500))/100;
// cout<<"Two thousand notes: "<<twothousand<<endl;
// cout<<"Five hundred notes: "<<fivehundred<<endl;
// cout<<"Hundred notes: "<<hundred<<endl;

//check if perfect square
int n,flag=0;
cout<<"enter your number:" <<endl;
cin>>n;
for(int i=0;i<n/2;i++){
    if(i*i==n){
        flag=1;
    }
    
    
}
if(flag==1){
    cout<<"given num is perfect square"<<endl;

}
else{
    cout<<"not perfect square"<<endl;
}


}