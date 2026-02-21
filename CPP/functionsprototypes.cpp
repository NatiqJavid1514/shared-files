#include <iostream>
using namespace std;

//like what we did with functions firsy defined them before int main we can do the same if we define it after int main
//The main thing is we need to set its prototype before defining it after int main.
const double pi{3.1481};
double area(double radius,double height);
void area_cylinder();

int main(){
    area_cylinder();


}

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