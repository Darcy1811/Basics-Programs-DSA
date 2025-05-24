#include <stdio.h>

void max(int *arr, int size){
        int maxNum=arr[0];
        int index=0;

        for(int i=1; i<size; i++){
            if(arr[i]>maxNum){
                maxNum=arr[i];
                index=i;
            }
        }

        printf("Maxnumber is %d, and index is %d.", maxNum, index);
}

void arrSort(int *arr, int n){

    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j+1]<arr[j]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("Sorted array is: ");
    for(int i=0; i<n; i++){
        printf("%d, ", arr[i]);
    }

}

int duplicateCheck(int *arr, int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]==arr[j]){
                return 1;
            }
        }
    }
}


int main(){
    int *arr, size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    arr=(int*)malloc(size*sizeof(int));

    printf("Enter elements of array: ");
    
    for(int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }

    max(arr, size);
    arrSort(arr, size);
    if(duplicateCheck(arr, size)==1){
        printf("yes");
    }
    else{
        printf("No");
    }

return 0;
}