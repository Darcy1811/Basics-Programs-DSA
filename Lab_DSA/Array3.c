#include <stdio.h>

int main(){
    int arr[20];
    int array[]={10, 15, 20, 40, 45, 50, 60, 100, 150, 200};

    for(int i=0; i<10; i++){
        arr[i]=array[i];
    }

    printf("Lower bound is %d, Upper boumd is %d, number present is %d\n", arr[0], arr[9], 10);
    printf("Multiples of 10 are: ");
    for(int i=0; i<10; i++){
        if(arr[i]%10==0){
            printf("%d, ", arr[i]);
        }
    }

    arr[10]=250;
    arr[11]=5;
    arr[12]=65;
    printf("\nNew array: ");
    for(int i=0; i<13; i++){
        printf("%d  ", arr[i]);
    }


    return 0;
}