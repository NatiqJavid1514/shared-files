#include <stdio.h>
#include <string.h>

int main(){
    int size,n,p,value;

    printf("Enter the size of array: ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter number of elements of array: \n");
    scanf("%d",&n);
    printf("Enter array elements: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter position  of element which you want to insert: \n");
    scanf("%d",&p);
    printf("Enter value of element: ");
    scanf("%d",&value);
    for(int i=n;i>=p;i--){
        arr[i]=arr[i-1];
    };
    arr[p-1]=value;
    n++;
    for(int i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }




    

    




}