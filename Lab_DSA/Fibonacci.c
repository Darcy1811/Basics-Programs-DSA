#include <stdio.h>

int Fibonacci(int n){
    if(n<=1){
        return n;
    }
    else{
        return Fibonacci(n-1)+Fibonacci(n-2);
    }
}

int main(){
    int n;
    printf("Enter: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
    printf("%d ", Fibonacci(i));
    }
       
return 0;
}