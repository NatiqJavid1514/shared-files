#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    int random_number{};
    size_t count{10}; // itne random number loop se generate karege
    int min {1}; // lower bound
    int max {8}; //upper bound
    

    // we need to seed the random multiplier so that we dont get the same result//

    cout<<"RAND-MAX on my system is: "<<RAND_MAX<<endl;
    for(int i{1}; i<count; i++){

        random_number=rand()%max+min;
        cout<<random_number<<endl;


    }
    cout<<endl;
    return 0;



}