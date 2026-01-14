#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector  <int> vector1 {};
    vector  <int> vector2 {};

    vector1.push_back(10);
    vector1.push_back(20);

    cout<<vector1.at(0)<<endl;
    cout<<vector1.at(1)<<endl;

    cout<<"Size of vector1 is "<<vector1.size()<<endl;

    vector2.push_back(100);
    vector2.push_back(200);

    cout<<vector2.at(0)<<endl;
    cout<<vector2.at(1)<<endl;

    cout<<"Size of vector2 is "<<vector2.size()<<endl;

    vector <vector <int>> vector3 {};
    vector3.push_back(vector1);
    vector3.push_back(vector2);

    cout<< "1st element of vector 3:"<< vector3.at(0).at(0)<<endl;

    
    vector1.at(0)=1000;
    
    cout<<vector3.at(0).at(0)<<endl;
    
    vector3.at(0).at(0)=1000;
    cout<< vector3.at(0).at(0)<<endl;



















}