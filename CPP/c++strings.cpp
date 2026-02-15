#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
 
    // string s0;
    // string s1{"Apple"};
    // string s2{"Bannana"};
    // string s3{"kiwi"};
    // string s4{"apple"};
    // string s5{s1};
    // string s6{s1,0,3};

    // cout<<s0<<endl;
    // cout<<s0.length()<<endl;


    //comparison

    // cout<<boolalpha;

    // cout<<s1<<" = "<<s2<<":"<<(s1==s2)<<endl;

    //assignment

    // string s1{"Nats"};
    // string s2{"Apple"};
    // string s3;
    // cout<<" String s1: "<<s1<<endl;

    // s1.at(0)='B';

    // cout<<s1<<endl;

    //concat

    // string s1{"Watermelon"};
    // string s2{"Apple"};
    // string s3{"Banana"};

    // // s1=s2+" and"+s3+"juice";

    // // cout<<"s1 is now: "<<s1<<endl;  

    // s1="nice"+"name"+s2;

    // cout<<s1;   //---------- YOU CANNOT ADD TWO C SYTLE STRING LITERALS---------///

    // string s1{"Apple"};  // using for loop for printing string//

    // for(size_t i{0}; i<s1.length();i++){

    //     cout<<s1.at(i);

    // }

    // same can be done by range based forloop//

    // for(auto c:s1){
    //     cout<<c;
    // }


    //substring--------------------------------------------//
    // string s1{"Aaj hoga test "};

    // cout<<s1.substr(0,3)<<endl;
    // cout<<s1.substr(5,2)<<endl;
    // cout<<s1.substr(10,2)<<endl; 

    //Erase//-------------------------------//

    // string s1{"This is a test"};
    // s1.erase(0,5);
    // cout<<s1;



    //getline

    // string full_name{};

    // cout<<"Enter your full name: "<<endl;
    // getline(cin,full_name);

    // cout<<" Your full name is "<<full_name<<endl;


    string s1{"The secret word is nats"};
    string word{};

    cout<<"Enter the word you want to find: "<<endl;

    cin>>word;

    size_t position=s1.find(word);

    if(position!=string::npos){

        cout<<"Found "<<word<<" at position "<<position<<endl;
    }
    else{
        cout<<"Sorry "<<word<<" not found"<<endl;
    }







    








}