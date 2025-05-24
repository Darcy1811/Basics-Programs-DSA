#include <stdio.h>

void printarr(int arr[], int size){
    for (int i = 0; i < size ; i++)
    {
        printf("%d  ", arr[i]);
    }
    
}

void insertion(int arr[], int index, int UB){
    for(int i=UB; i>=index; i--){
            arr[i+1]=arr[i];

    }
 arr[index]=3;
 printarr(arr, UB+1);
}

void  deletion(int arr[], int value, int size){
    for(int i=0; i<size; i++){
        if(arr[i]==value){
            for(i+1; i<size-1; i++){
                arr[i]=arr[i+1];
            }
        }
    }
    printarr(arr, size-1);

}

int main(){
    int n, index;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        printf("Enter element %d: \n", i);
        scanf("%d", &arr[i]);
    }
    printf("Enter index at which you want: ");
    scanf("%d", &index);

    insertion(arr, index);
    //deletion(arr, 4, n);


    return 0;
}