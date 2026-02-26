#include <iostream>
using namespace std;
#include <string>
#include <vector>
// lets make 4 pass by value functions//
void pass_by_value1(int num);
void pass_by_value2(string s);
void pass_by_value3(vector<string> v);
void pass_by_value4(vector<string> v);

void pass_by_value1(int num){
    num=1000;
    cout<<num;
}
void pass_by_value2(string s){
    s="NATS";

}
void pass_by_value3(vector<string> v){
    v.clear()

}

void print(vector<string> t){
    for(auto uwu:t){
        cout<<uwu;
        cout<<" ";
    }
}

int main(){

    // int num{10};
    // int another_num{20};

    // cout<<"num before passing the value is: "<<num<<endl;
    // pass_by_value1(num);
    // cout<<"num after passing the value is: "<<num<<endl;
    // here the value doesnt change because we are editing a copy of num and printing actual num on the screen//

    /* same happens with when you do it with strings.*/

    // string name{"Nats"};
    // cout<<"\nName before changing is: "<<name<<endl;
    // pass_by_value2(name);
    // cout<<"\nName after changing is: "<<name<<endl;

    vector<string> names{"Nats","bats","chats"};

    print(names);

    pass_by_value3(names);

    print(names);

    // yeh erase nanhi hua kyunki humne iski copy ko erase kiya na ki iss vector ko









}

