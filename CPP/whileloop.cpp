#include <iostream>
#include <vector>

using namespace std;


int main(){

    // int num{};
    // cout<<"Enter a positive integer - start the countdown: ";
    // cin>>num;

    // while(num>0){

    //     cout<<num<<endl;
    //     --num;




    // }


//     int num{};

//     cout<<"Enter a positive integer - start the count down: ";
//     cin>>num;
//     while(num<3){

//         cout<<num<<endl;
//         ++num;
//     }

//    cout<<"BLASTOFF!!"<<endl;

//    cout<<endl;  
   
//    return 0;

     bool done{false};
     int num{};

     while(!done){
        cout<<"Enter an Integer between 1 and 5: "<<endl;
        cin>>num;
        if(num<=1 || num>=5){

            cout<<"Out of range, try again"<<endl;



        }
        else{
            cout<<"Thanks!"<<endl;
            done=true;  
        }
     }




   






}

