#include <stdio.h>

int exponent(int x, int y){
    if(y==1){
        return x;
    }
    else{
        return x*exponent(x, y-1);
    }
}

int main(){
    int x, y;
    printf("Enter no");
    scanf("%d", &x);
    scanf("%d", &y);
    printf("%d", exponent(x, y));
    return 0;
}