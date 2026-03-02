#include <iostream>
using namespace std;
#include <vector>
#include <string>
void print_array(int numbers[], size_t size){
    for(size_t i{0}; i<size; i++){
        cout<<numbers[i]<<endl;
    }
}
void set_array(int numbers[], size_t size, int value){
    for(size_t i{0}; i<size; i++){
        numbers[i]=value;
    }
}


int main(){
    int my_numbers[] {100,99,98,97,96};
    print_array(my_numbers,5);
    set_array(my_numbers,5,100);
    print_array(my_numbers,5);



}

