#include <iostream>
#include <stack>
#include <vector>
#include <list>
using namespace std;

void display(stack <int> s){
    for(int i=0;i<=s.size();i++){
        int x=s.top();
        cout<<x<<endl;
        s.pop();

    }
}
void test1(){
    stack <int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    display(s);
}
int main(){
    test1();
    
}