#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cctype>
#include <list>
using namespace std;
void findtest(){
    vector <int> nums{1,2,3,4,5};
    auto it= find(nums.begin(),nums.end(),2);
    if(it!=nums.end()){
        cout<<"number found "<<*it<<endl;

    }
    else{
        cout<<"num not found"<<endl;
    }

}
void counttest(){
    vector <int> nums{1,2,3,4,5,1,1,1};
    int num= count(nums.begin(),nums.end(),1);
    cout<<"number of occurances of 1 are: "<<num<<endl;

    
}
int even(int x){
    if(x%2==0)
    return x;
}
void countiftest(){
    vector <int> nums{1,2,4,5,6,7,8};
    int num=count_if(nums.begin(),nums.end(),even);
    cout<<" number of even elements are: "<<num<<endl;

}
void replacetest(){
    vector <int> nums{1,2,3,4,5,1,1,1};
    for(auto i:nums){
        cout<<i<<" ";
    }
    cout<<endl;

    replace(nums.begin(),nums.end(),1,100);
    for(auto i:nums){
        cout<<i<<" ";
    }
}
int greaterthan10(int x){ 
    if(x>10){
    return x;}
    return 0;
};
void alloftest(){
    vector <int> nums {20,30,40,50};
    if(all_of(nums.begin(),nums.end(),greaterthan10)){
        cout<<"all numbers are greater than 10"<<endl;
    }
    else{
        cout<<"not greater than 10"<<endl;
    }
}
void testtransform() {
    string s1 {"nats is bats"
    };
    transform(s1.begin(),s1.end(),s1.begin(),::toupper);
    cout<<s1<<endl;
}



int main(){

    //findtest();
   // counttest();
   //countiftest();
  // replacetest();
  //alloftest();
  testtransform();

}