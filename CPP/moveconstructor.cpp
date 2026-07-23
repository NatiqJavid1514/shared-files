#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Move{
    private:
    int *data;

    public:
    void set_data(int d){
        *data=d;
    }
    int get_data(){
        return *data;
    }
    Move(int d){
        data= new int;
        *data=d;
        cout<<"constructor for "<<d<<endl;
    }
    ~Move(){
        if(data!=nullptr){
            cout<<"Destructor freeing data for"<<*data<<endl;}
            else{
                cout<<"Destructor freeing data for nullptr"<<endl;

            
        

            }
            delete data;
}
Move(Move &&source)noexcept: data{source.data} {
    source.data=nullptr;
    cout<<"Move constructor moving resource for "<<*data<<endl;
}
    


};

int main () {
    vector<Move> vecs;
    vecs.push_back(Move(10));
}