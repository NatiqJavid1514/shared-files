#include <iostream>
#include <string>
#include <set>
#include <unordered_set>
using namespace std;
void display(set <int> &s){
    cout<<"[ ";
    for(auto c:s){
        cout<<c<<" ";

    }
    cout<<"]";
    cout<<endl;
}
void display2(set <string> &s){
    cout<<"[ ";
    for(auto c:s){
        cout<<c<<" ";

    }
    cout<<"]";
    cout<<endl;
}

void test1() {
    set <int> nums {1,2,3,4,5};
    display(nums);
    nums.insert(8);
    display(nums);
    cout<<nums.count(4)<<endl;
    auto it=nums.find(3);
    if(it!=nums.end()){
        cout<<*it<<" Is found"<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }
    nums.clear();
    display(nums);

}
void test2(){
    set <string> let{"A","B","C"};
    display2(let);
    cout<<boolalpha;
    auto it=let.insert("D");
    cout<<*(it.first)<<endl;
    cout<<(it.second)<<endl;
}
int main (){
   // test1();
   cout<<boolalpha;
   test2();

}