#include <iostream>
#include <string>
using namespace std;
class deep{
    int *data;

    public:
    void set_data(int d){
        *data=d;
    }
    int get_value(){
        return *data;
    }
    deep(int d);          //constructor
    deep(const deep &source);   //copy constructor
    ~deep();  //destructor
};
deep::deep(int d){
    data=new int;
    *data=d;
};
deep::deep(const deep &source):data{source.data} {
    data=new int;
    *data=*source.data;
    cout<<"copy constructor called"<<endl;
    

}
deep::~deep(){
    delete data;
    cout<<"destructor called for data"<<endl;
}
void display_deep(deep s){
    cout<<s.get_value()<<endl;
};
int main(){
     deep obj1(100);
     display_deep(obj1); // yahan par original object bhi delete hogaya 
     deep obj2 {obj1};
     obj2.set_data(1000); // here we have two objects pointing to invalid address


}