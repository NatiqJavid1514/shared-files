#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>
using namespace std;
class Player{
    private:
    string name;
    int age;

    public:
    Player(string s,int a){
        name=s;
        age=a;
    };
};

using namespace std;
void display(deque<int> &d){
    cout<<"[ ";
    for(auto c:d){
        cout<<c<<" ";

    }
    cout<<"]";
    cout<<endl;
}

void test1(){
    deque <int> nums {1,2,3,4,5};
    display(nums);
    nums.pop_front();
    display(nums);
    nums.push_front(1);
    display(nums);
    cout<<nums.max_size()<<endl;
    cout<<nums.size()<<endl;

}
void test2(){
    //insert even numbers in back of deque and odd numbers in front//
    deque <int> nums {1,2,3,4,5,6,7,8,9,10};
    deque <int> nums2;
    for(auto c:nums){
        if(c%2==0){
            nums2.push_back(c);
        }
        else{
            nums2.push_front(c);
        }
    }
    display(nums);
    display(nums2);

}
void test3(){
    deque <int> num{1,2,3,4,5};
    deque <int> num2;
    copy(num.begin(),num.end(),front_inserter(num2));
    display(num2);
}
int main() {
    //test1();
    //test2();
    test3();



    
    


     



}