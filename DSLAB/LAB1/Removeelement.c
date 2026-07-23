#include <stdio.h>
#include <string.h>

int main(){
    int size,n,p;

    printf("Enter the size of array: ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter number of elements of array: \n");
    scanf("%d",&n);
    printf("Enter array elements: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the position element you want to delete: \n");
    scanf("%d",&p);
    for(int i=p;i<=n;i++)


}