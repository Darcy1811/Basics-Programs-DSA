#include <stdio.h>

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}


void printarr(int arr[], int size){
    for (int i = 0; i < size ; i++)
    {
        printf("%d  ", arr[i]);
    }
    
}

void insertion(int arr[], int n){
for(int i=0; i<n-1; i++){
    int min=i;
    for(int j=i+1; j<n; j++){
        if(arr[j]<arr[min]){
            min=j;
        }
    }
    
    if(min!=i){
        swap(&arr[i], &arr[min]);
    }
}

}

int main(){
    int arr[9]={9,4,6,2,5,3,7,1,8};
    insertion(arr, 9);
    printarr(arr, 9);
       
return 0;
}