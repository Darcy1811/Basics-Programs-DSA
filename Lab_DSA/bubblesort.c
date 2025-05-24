//Time Complexity is O(n^2)

#include <stdio.h>

void printArr(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d  ", arr[i]);
    }
}

void bubbleSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1 ; j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printArr(arr, n);
}

int main(){
    int arr[]={1,5,2,9,4,5,99,66,3,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, size);

       
return 0;
}