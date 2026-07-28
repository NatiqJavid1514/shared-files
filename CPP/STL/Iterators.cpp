#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
using namespace std;
void display(vector <int> vec){
    for(auto n:vec){
        cout<<n<<" ";
    }

}
void test1() {
    vector <int> nums {10,20,30,40,50};
    auto it=nums.begin(); //iterator banadiya
    cout<<*it<<endl;
    it++;
    cout<<*it<<endl;
    it+=2;
    cout<<*it<<endl;

    it=nums.end()-1;
    cout<<*it<<endl;

}
void test2() {
    vector <int> num1 {1,2,3,4,5};
    vector <int>::iterator it=num1.begin();
    while(it!=num1.end()){
        cout<<*it<<endl;
        it++;
    }
    it=num1.begin();
        while(it!=num1.end()){
        *it=0;
        it++;
    }
    display(num1);
    
}
void test3(){
    vector <int> nums{10,20,30,40};
    auto it=nums.rbegin();
    while(it!=nums.rend()){
        cout<<*it<<endl;
        it++;
    }
}
void test4(){
    list <string> names {"nats","bats","cats"};
    auto it2=names.crbegin(); //constant reverse iterator to names;
    cout<<*it2<<endl;
    it2++;
    cout<<*it2<<endl;
    
}
void test5(){
    map <string,string> favorites{
        {"natiq","c++"},
        {"saleet","dsa"},
        {"babi","sleep"}
    };
    auto it3 =favorites.begin();
        while(it3!=favorites.end()){
            cout<<it3->first<<" likes "<<it3->second<<endl;
            it3++;
        }
        

}
int main() {
    // test1();
   // test2();
  // test3();
  // test4();
  test5();

}