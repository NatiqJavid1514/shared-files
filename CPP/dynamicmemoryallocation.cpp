#include <iostream>
using namespace std;
int main(){
    int *int_ptr {nullptr};
    int_ptr=new int;    //yeh maine heap mai aik integer ki jagah banadi jisko int_ptr point kar raha hai//

    cout<<int_ptr<<endl; 
    *int_ptr=100;
    cout<<*int_ptr<<endl;

    delete int_ptr;              //necessary to delete the space acquired by this pointer in heap//

    size_t size {0};
    double *temp_ptr;
    cout<<"How many temps: "<<endl;
    cin>>size;

    temp_ptr=new double[size];   // matlab naye doubles create karo heap mai.. kitne?? size jitne

    delete [] temp_ptr;

    
     

}