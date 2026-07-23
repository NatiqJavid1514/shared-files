#include <iostream>
#include <string>
using namespace std;
class Shallow{
    int *data;

    public:
    void set_data(int d){
        *data=d;
    }
    int get_value(){
        return *data;
    }
    Shallow(int d);          //constructor
    Shallow(const Shallow &source);   //copy constructor
    ~Shallow();  //destructor
};
Shallow::Shallow(int d){
    data=new int;
    *data=d;
};
Shallow::Shallow(const Shallow &source):data{source.data} {
    cout<<"copy constructor called-"<<endl;

}
Shallow::~Shallow(){
    delete data;
    cout<<"destructor called for data"<<endl;
}
void display_shallow(Shallow s){
    cout<<s.get_value()<<endl;
};
int main(){
     Shallow obj1(100);
     display_shallow(obj1); // yahan par original object bhi delete hogaya 
     Shallow obj2 {obj1};
     obj2.set_data(1000); // here we have two objects pointing to invalid address


}