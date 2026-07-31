#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cctype>
using namespace std;

void display(array <int,5> &arr){
    auto it=arr.begin();
    cout<<"[ ";
    while(it!=arr.end()){
        cout<<*it<<" ";
        it++;
    }
    cout<<" ]";
    cout<<endl;
}
void test1(){
    array <int,5> arr {10,20,30,40,50};
    array <int,5> arr2;
    arr2={1,2,3,4,5};
    cout<<arr.size()<<endl;
    cout<<arr.front()<<endl;
    cout<<arr.empty()<<endl;

}
void test2(){
    array <int,5> arr {10,20,30,40,50};
    array <int,5> arr2 {100,200,300,400,500};
    display(arr);
    display(arr2);
    arr.swap(arr2);
    display(arr);

    
    arr.fill(0);
    display(arr);

}
void test3() {
    array <int,5> arr {10,20,30,40,50};
    int *ptr=arr.data();
    cout<<ptr<<endl;
    *ptr=10000;
    display(arr);
    
}
int between(int x){
    if(x>40&&x<500)
    return x;
    else 
    return 0;
}
void test4(){
    array <int,5> arr {101,20,3,43,221};
    sort(arr.begin(),arr.end());
    display(arr);
    auto it=max_element(arr.begin(),arr.end());
    cout<<"max element is "<<*it<<endl;
    auto it2=min_element(arr.begin(),arr.end());
    cout<<"min element is "<<*it2<<endl;
    int num=count_if(arr.begin(),arr.end(),between);
    cout<<"Number of elements between 40 and 500 are: "<<num<<endl;

    
}

int main() {
    
    //test1();
    //test2();
    //test3();
      test4();

}