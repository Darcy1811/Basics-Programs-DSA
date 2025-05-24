#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int palindrome(char str[]){
    int len= strlen(str);

    for(int i=0;i<len;i++){
        if(str[i]!=str[len-1 -i]){
            return false;
        }
    }

    return true;
}

int main(){
   char str[100];
   scanf("%s",str);

   int len = strlen(str);

    if (palindrome(str)){
        printf("string is a palindrome\n");
    }
    else {
        printf("string is not a palindrome \n");
    }

    for(int i=0;i<len;i++){
        printf("%c",str[len-1-i]);
    }
    return 0;
}
