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

int Partition(int a[], int LB, int UB){
    int pivot =a[LB];
    int start=LB;
    int end=UB;

    while(start<end){
        while(a[start]<=pivot){
            start++;   
        }
        while(a[end]>pivot){
            end--;
        }
        if(start <end){
            swap(&a[start], &a[end]);
        }
    }
    swap(&a[LB], &a[end]);
    return end;
}

void quickSort(int arr[], int LB, int UB){
    if(LB<UB){
    int loc=Partition(arr, LB,UB);
    quickSort(arr, LB, loc-1);
    quickSort(arr, loc+1, UB);
    }
}

int main(){
    int arr[9]={9,4,6,0,5,3,7,1,8};
    quickSort(arr, 0, 9);
    printarr(arr, 9);
       
return 0;
}