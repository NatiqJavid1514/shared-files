#include <iostream>
#include <vector>
using namespace std;
void display(int arr[],int size){
    cout<<"[ ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"]";
}

int main(){
    // int arr[5] {1,2,3};
    // display(arr,5);
    // for(int i=3;i>=1;i--){
    //     arr[i+1]=arr[i];
    // }
    // arr[1]=10;
    // display(arr,5);
    int arr[5] {1,2,3,4,5};
    int pos;
    cout<<"enter position of element you want to delete: ";

    cin>>pos;

    arr[pos-1]=0;
    for(int i=(pos);i<5;i++){
        arr[i-1]=arr[i];
    }
    arr[4]=0;
    display(arr,5);
    




}