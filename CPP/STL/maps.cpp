#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
void display(map <string,int> &I){
    cout<<"[ ";
    for(auto elem:I){
        cout<<elem.first<<": "<<elem.second<<" ,";
    }
    cout<<"]";
}

void test1() {
    map <string,int> data {
        {"natiq",18},
        {"Babar",17},
        {"lakshita",20}

    };
    display(data);
    data.insert(pair<string,int>("ilha",21));
    display(data);
}





int main() {
    test1();


}