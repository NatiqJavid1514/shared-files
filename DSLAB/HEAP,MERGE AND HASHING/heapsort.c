#include<stdio.h>
void heapSort(int arr[], int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
}
void heapify(int A[],int n,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<=n && A[l]>A[largest]){
        largest=l;
    }
    if(r<=n && A[r]>A[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(&A[largest],&A[i]);
        heapify(A,n,largest);
    }
}
void swap(int *a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main(){
    int arr[]={12,11,13,5,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    heapSort(arr,n);
    printf("Sorted array is \n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}