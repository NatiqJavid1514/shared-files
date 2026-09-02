#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){

    int num{100};
    int &ref{num};
    cout<<num<<endl;
    cout<<ref<<endl;
    vector <string> names{"Nats","Bats", "cats"};
        for(auto &c:names){
        
        c="funny";
        
    }
    for(auto c:names){
        
        cout<<c<<endl;
        
    }
    


}