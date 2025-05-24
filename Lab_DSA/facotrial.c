#include <stdio.h>

int factorial(int num){
    if(num==1){
        return 1;
    }
    else{
        return num*factorial(num-1);
    }
}
int main(){
     int num;
     printf("Enter number: ");
     scanf("%d", &num);

     int a=factorial(num);

     printf("%d", a);



return 0;
}