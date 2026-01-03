/* we have to display this in the terminal
First it asks for our favorite number
Then we enter our favorite number
Then it replies " Amazing that's my favorite number too
No really x is my favorite number"
Our favorite number should display in the code */

#include <iostream>

int main(){
    int favorite_number;

    std::cout<<"Enter your favorite number:";
    std::cin>>favorite_number;
    std::cout<<"Amazing thats my favorite number too"<<std::endl;
    std::cout<<"No really!! " <<favorite_number<< " is my favorite number";

    return 0;
}
/* 
String+int doesn't work in CPP 
So for insertion of int between strings 
we go for [<< <<]..
Remember this. Because we need to keep inserting */