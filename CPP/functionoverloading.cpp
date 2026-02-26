#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
void print(int);
void print(double);
void print(string);
void print(string,string);
void print(vector<string>);
/*overloaded functions with default arguments are to be used carefully as if we print for eg print(); it will print the void which has default
value assigned to it, if two have default value assigned it will print error*/


void print(int num){
    cout<<"Printing int: "<<num<<endl;

};
void print(double num){
    cout<<"Printing double: "<<num<<endl;

};
void print(string s){
    cout<<"Printing string: "<<s<<endl;

};
void print(string s,string x){
    cout<<"Printing strings "+s+" "+x<<endl;
}
void print(vector<string> i){
    cout<<"Printing names: ";
    for(auto j:i){
        cout<<j;
        cout<<" ";

    }
}





int main(){

    print(100); //will print int
    print('A'); // characters are always promoted to integers so it will print its representing ASCII value that is 65//

    print(123.5); //double printed
    print(123.5F); //floating but it will match the double it will be promoted to double

    /* what about c style strings----------- C style string is always converted to c++ string object */

    string s{"c++ style string"};

    print(s); //c++style string printed

    print("c-style string"); // c-style converted and printed

    vector<string> names{"Nats", "bats", "chats"};

    print(names);



}