#include <iostream>
#include <vector>
#include <string>

using namespace std;
void pass_by_ref1(int &num);
void pass_by_ref2(string &s);
void pass_by_ref3(vector<string> &v);
void print_vector(const vector<string> &v);

void pass_by_ref1(int &num){
    num=1000;
};
void pass_by_ref2(string &s){
    s="changed;";
};
void pass_by_ref3(vector<string> &v){
    v.clear();
}

void print_vector(const vector<string> &v){
    for(auto uwu:v){
        cout<<uwu<<" ";
    }
    cout<<endl;
};







int main(){

    int a{10000};
    pass_by_ref1(a);

    cout<<a;



}