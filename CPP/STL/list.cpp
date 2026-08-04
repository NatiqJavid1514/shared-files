#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <iterator>

using namespace std;

void display(list <int> &l){
    cout<<"[ ";
    for(auto c:l){
        cout<<c<<" ";
    }
    cout<<"]";
    cout<<endl;
}

void test1(){
    list <int> l{1,2,3,4,5};
    display(l);
}
void test2(){
    list <int> l{2,1,3,2,4};
    cout<<l.back()<<endl;
    cout<<l.front()<<endl;
   // sort(l.begin(),l.end());
    display(l);
    cout<<l.size()<<endl;
    l.push_back(100);
    display(l);

}
void test3(){
    list <int> l{2,1,3,2,4};
    list <int> l2{100,200,300,400};
    auto it=find(l.begin(),l.end(),3);
    if(it!=l.end()){
        l.insert(it,l2.begin(),l2.end());

    }
    display(l);
}

int main(){
    //test1();
    //test2();
    test3();

}