#include <iostream>
using namespace std;
int *create_array(size_t size, int values){
    int *newarr{nullptr};
    newarr= new int[size];
    for(int i=0;i<size;i++){
        newarr[i]=values;
    }
    return newarr;

}

int main(){
    int *myarray;
    myarray=create_array(5,20);
    for(int i=0;i<5;i++){
        cout<<*myarray<<endl;
        myarray++;
    }

   
         
}
