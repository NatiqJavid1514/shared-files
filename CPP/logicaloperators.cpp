#include <iostream>
using namespace std;

int main(){
  int num{};
  const int lower{10};
  const int higher{20};
  cout<<boolalpha;
  //if a number lies between two numbers//

  cout<<"Enter your Integer between "<<lower<<" and "<<higher<<endl;
  cin>>num;

  bool within_bounds{};
  within_bounds=(num>10)&&(num<20);

  cout<<"within bounds is: "<<within_bounds<<endl;


  //if an integer lies exactly on the boundary//
  cout<<"Enter your Integer between "<<lower<<" and "<<higher<<endl;
  cin>>num;

  bool on_boundary{};
  on_boundary=(num=10)||(num=20);

  cout<<"on boundary  is: "<<on_boundary<<endl;

}