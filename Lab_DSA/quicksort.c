#include <stdio.h>
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int Partition(int arr[], int LB, int UB){
    int pivot=arr[LB];
    int start=LB;
    int end=UB;
    while(start<end){
        while(arr[start]<=pivot){
            start++;
        }
        while(arr[end]>pivot){
            end--;
        }
        if(start<end){
            swap(&arr[start], &arr[end]);
        }
    }
    swap(&arr[LB], &arr[end]);
    return end;
}

void QuickSort(int arr[], int LB, int UB){
    if(LB<UB){
    int loc=Partition(arr, LB, UB);
    QuickSort(arr, LB, loc-1);
    QuickSort(arr, loc+1, UB);
}
}

void PrintArr(int arr[]){
    for(int i=0; i<9; i++){
        printf("%d  ", arr[i]);
    }
}

int main(){
    //int n;
    //printf("Enter the size of array: ");
    //scanf("%d", &n);
    int arr[9]={7,6,10,5,9,2,15,7};
    /*printf("Enter input in array");

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    */
   QuickSort(arr, 0, 8);
   PrintArr(arr);

       
return 0;
}