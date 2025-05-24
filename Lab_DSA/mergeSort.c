#include <stdio.h>
#include <stdlib.h>
void merge(int A[], int lb, int mid, int ub);

void mergesort(int A[], int lb, int ub){
    if(lb<ub){
        int mid = (lb + ub)/2;
        mergesort(A, lb, mid);
        mergesort(A, mid+1, ub);
    merge(A, lb, mid, ub);
    }
}
void merge(int A[], int lb, int mid, int ub){
    int i=lb;
    int j = mid + 1;
    int k = lb;
    int b[ub - 1];
    while(i<mid && j<=ub){
        if(A[i] <= A[j]){
            b[k] = A[i];
            i++;
        }else{
            b[k] = A[j];
            j++;
            k++;
        }if(i>mid){
            while(j<=ub){
                b[k] = A[j];
                 j++;
                 k++;            
            }
        }else{
            while(i <= mid){
                b[k] = A[i];
                i++;
                k++;
            }
            for(int x = lb; x<=ub; x++){
                A[x] = b[x];
            }
        }
    }
}
int main(){
    int n;
    int lb = 0;
    int ub = n - 1;
    printf("Enter the size of the elements: ");
    scanf("%d", &n);

    int Arr[n];

    printf("Enter the elements of the array: ");
    for(int i = 0; i<n; i++){
        scanf("%d", &Arr[i]);
    }
    mergesort(Arr,lb,ub);
    printf("Sorted array: \n");
    for(int i = 0; i<n; i++){
        printf("%d", Arr[i]);
    }
}