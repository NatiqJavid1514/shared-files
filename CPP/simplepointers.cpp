#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

    int num{10};
    cout<<"value of num is: "<<num<<endl;
    cout<<"size of num is: "<<sizeof num<<endl;
    cout<<"Address of num is: "<<&num<<endl;

    //declaring pointer.
    int *p;
    cout<<"\nValue of p is: "<<p<<endl; //garbage
    cout<<"Address of p is: "<<&p<<endl;
    cout<<"size of p is: "<<sizeof p<<endl;
}