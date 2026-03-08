#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
//   int score{100};
//   int *score_ptr {&score};

//   cout<<*score_ptr<<endl;

//   *score_ptr=200;
//   cout<<*score_ptr<<endl;;
//   cout<<score<<endl; // we changed the value

//  string s1{"Natiq"};
//  string *str_ptr{&s1};

//  cout<<*str_ptr<<endl;

//  *str_ptr="Javid";

//  cout<<*str_ptr<<endl;
//  cout<<s1<<endl;

vector<string> names{"nats","bats","lats"};

vector<string> *vec_ptr{&names};

cout<<"First name is: "<<(*vec_ptr).at(0)<<endl;

for(auto c:*vec_ptr){
    cout<<c<<" ";
}
 




}