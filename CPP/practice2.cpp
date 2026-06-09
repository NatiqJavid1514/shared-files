#include <iostream>
using namespace std;
#include <vector>
#include <cmath>

int main(){
    int num{};
    cout<<"Enter your number: "<<endl;
    cin>>num;
    int numcpy=num;
    int count{0};
    
    int remainder{};
    int sum{0};

    while(numcpy!=0){
        remainder=numcpy%10;
        count++;
        numcpy=numcpy/10;
        



    }
    numcpy=num;
    while(numcpy!=0){
        remainder=numcpy%10;
        sum+=round(pow(remainder,count));
        numcpy=numcpy/10;
    }
    
    
    cout<<sum<<endl;



    
}