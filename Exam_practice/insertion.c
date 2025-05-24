#include <stdio.h>

void printarr(int arr[], int size){
    for (int i = 0; i < size ; i++)
    {
        printf("%d  ", arr[i]);
    }
    
}

void insertion(int arr[], int n){
int temp, j;
   for(int i=1; i<n; i++){
    temp=arr[i];
    j=i-1;
    while(j>=0 && arr[j]>temp){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=temp;
   }

}

int main(){
    int arr[9]={9,4,6,2,5,3,7,1,8};
    insertion(arr, 9);
    printarr(arr, 9);
       
return 0;
}