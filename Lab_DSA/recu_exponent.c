#include <stdio.h>
int exponent(int x, int y){
    if(y==1){
        return x;
    }
    else{
        return (x*exponent(x, y-1));
    }
}

int main(){
    int x, y;
    printf("Enter a number: ");
    scanf("%d", &x);
    scanf("%d", &y);

    printf("Result is %d.", exponent(x,y));

       
return 0;
}