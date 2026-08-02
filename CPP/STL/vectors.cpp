#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void display(vector <int> &vec){
    cout<<"[ ";
    for(auto x:vec){
        cout<<x<<" ";
    }
    cout<<" ]";
    cout<<endl;

}
void test1(){
    vector <int> vec1{10,20,30,40,50 };
    vector <int> vec2{1,2,3,4,5};
    display(vec1);
    cout<<vec1.front()<<endl;
    cout<<vec1.back()<<endl;
    
}
void test2() {
    vector <int> vec2{1,2,3,4,5};
    display(vec2);
    auto it=vec2.begin();
  //  vec2.erase(vec2.begin(),vec 2.begin()+2); 
    while(it!=vec2.end()){
        if(*it%2==0){
          vec2.erase(it);             
        }
        else {
            it++;   // Warna increment
        }
    }
    display(vec2);


}
void test3() {
    vector <int> vec1{1,2,3,5,6};
    vector <int> vec2{100,200,300,400};
    display(vec1);
    display(vec2);
    vec1.swap(vec2);
    display(vec1);
    
}


int even(int x){
    if(x%2==0){
        return x;
    }
    else{
    return 0; }
    

}
int multiply(int x,int y){
     return x*y;
    
}

void test4(){
    vector <int> vec1{1,2,3,5,6};
    vector <int> vec2{200,300,100,300};
    vector <int> vec3;
    display(vec1);
    //sort(vec2.begin(),vec2.end());
    display(vec2);
    // copy(vec1.begin(),vec1.end(),back_inserter(vec2));
    // copy_if(vec1.begin(),vec1.end(),back_inserter(vec2),even);
   transform(vec1.begin(),vec1.end(),vec2.begin(),back_inserter(vec3),multiply);
   display(vec3);


    

    


}
void test5(){
    vector <int> vec1{1,2,3,5,6};
    vector <int> vec2{200,300,100,300};
    auto it=find(vec1.begin(),vec1.end(),5);
    if(it!=vec1.end()){
        cout<<"Inserting second vector "<<endl;
        vec1.insert(it,vec2.begin(),vec2.end());

    }
    else{
        cout<<"element not found "<<endl;

    }
    display(vec1);
    
}
int main () {
   // test1();
      //test2();
  
  //  test3();
 // test4();
    //test5();




}