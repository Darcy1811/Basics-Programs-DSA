#include <stdio.h>

void printarr(int arr[], int size){
    for (int i = 0; i < size ; i++)
    {
        printf("%d  ", arr[i]);
    }
    
}

void bubblesort(int arr[], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];*********************************************
                arr[j+1]=temp;
            }
        }
    }
    printarr(arr, n);

}

int main(){
    int arr[9]={9,4,6,2,5,3,7,1,8};
    bubblesort(arr, 9);
       
return 0;
}