#include <stdio.h> 
#include <stdlib.h> 

int main(){ 
    int arr[5], n, i, j, temp; 
    int count = 0; 

    printf("Enter the number of elements: \n"); 
    scanf("%d", &n); 

    printf("Enter array Elements:\n"); 
    for(int i = 0; i < n; i++){ 
        scanf("%d", &arr[i]); 
    } 

    
    for(int i = 0; i < n - 1; i++){ 
        for(int j = 0; j < n - 1 - i; j++){ 
            if(arr[j] > arr[j + 1]){ 
                temp = arr[j]; 
                arr[j] = arr[j + 1]; 
                arr[j + 1] = temp; 
                
                count++; 
            } 
        } 
    } 

    printf("Sorted array is :\n"); 
    printf("["); 
    for(int i = 0; i < n; i++){ 
        printf(" %d ", arr[i]); 
    } 
    printf(" ]\n"); 

    
    printf("Total number of swaps: %d\n", count); 

    return 0;
}
