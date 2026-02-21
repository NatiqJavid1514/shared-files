#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Area of circle
//Area of cylinder functions

// const double pi {3.1481};

// using namespace std;
//     double area(double radius){
//         return pi*radius*radius;

        

// }

// int main(){
//     double radius{};
//     double uwu{};
//     const double pi {3.1481};

//     cout<<"Enter your radius: ";
//     cin>>radius;





// cout<<"Your area is "<<area(radius)<<endl;


    


    




// }
// this was for circle for cylinder we'll use another method we will only call function no cout nothing 
// we'll use void and double to solve the problem

// for cylinder

const double pi{3.1481};

double area(double radius,double height){
    return pi*radius*radius*height;

}

void area_cylinder(){
    double radius{};
    double height{};
    cout<<"Enter radius of cylinder"<<endl;
    cin>>radius;
    cout<<"Enter height of cylinder"<<endl;
    cin>>height;

    cout<<"Area of the cylinder with radius "<<radius<<" and height "<<height<<" is "<<area(radius,height)<<endl;

}
int main(){

    area_cylinder();


}