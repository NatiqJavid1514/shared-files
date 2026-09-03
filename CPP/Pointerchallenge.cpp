#include <iostream>
#include <vector>
#include <string>
using namespace std;
int *apply_all(int arr[],int size1,int arr2[],int size2){
    
    int *baseptr;
    int *ptr= new int[size1*size2];
    baseptr=ptr;
    for (int j=0;j<size1;j++) {
        for(int k=0;k<size2;k++){
            
                *ptr=(arr[j]*arr2[k]);
                ptr++;
            
        }
    }
    ptr=baseptr;
    return ptr;

   }





int main(){
    int arr[5]{10,20,30,40,50};
    int arr2[3] {1,2,3};

    int *result=apply_all(arr,5,arr2,3);

    for(int i=0;i<15;i++){
         cout<<*result<<endl;
         result++;
    }




}