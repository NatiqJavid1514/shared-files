#include <iostream>
using namespace std;
// do while simple menu example

int main(){

    char selection{};

    do{
        cout<<"\n-------------------------------------"<<endl;
        cout<<"1. Do this"<<endl;
        cout<<"2. Do that"<<endl;
        cout<<"3. Do something else"<<endl;
        cout<<"4. Quit"<<endl;

        cin>>selection;

        if(selection=='1')


    }

    while(selection=='q'&& selection=='Q');{

        cout<<"Sayonara"<<endl;

    }








}