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
        cout<<"Q. Quit"<<endl;

        cout<<"\nEnter your selection: "<<endl;

        cin>>selection;

        if(selection=='1'){
            cout<<"You chose 1 doing this"<<endl;

        }
        else if(selection=='2'){
            cout<<"You chose 2 doing that"<<endl;


        }
        else if(selection=='3'){
            cout<<"you chose 3 doing something else"<<endl;

        }

        else if(selection=='Q' || selection=='q'){
            cout<<"goodbye!!"<<endl;
        }
        else{
            cout<<"unknown option"<<endl;
        }


    } while(selection!='q'&& selection!='Q');
  



    return 0;
        

    








}