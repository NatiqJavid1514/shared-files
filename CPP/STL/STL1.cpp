#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main(){
 vector <int> v{1,3,4,2,5};
//  for(auto e:v){
//     cout<<e<<endl;

//  }
 sort(v.begin(),v.end());
  for(auto e:v){
    cout<<e<<endl;

 }
 int sum;
 sum=accumulate(v.begin(),v.end(),10);
 cout<<sum<<endl;


 

}