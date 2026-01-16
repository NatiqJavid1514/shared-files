#include <iostream>
using namespace std;

int main(){

    int result {0};



    int num1 {200};
    int num2 {500};

    cout<<num1<<"+"<<num2<<"="<<num1+num2<<endl;

    result=num1-num2;
    
    cout<<num1<<"-"<<num2<<"="<<result<<endl;

    result=num1*num2;

    cout<<num1<<"*"<<num2<<"="<<result<<endl;

    result=num1/num2;

    cout<<num1<<"/"<<num2<<"="<<result<<endl;

    result=num2 % num1;

    cout<<num2<<"%"<<num1<<"="<<result<<endl;




}