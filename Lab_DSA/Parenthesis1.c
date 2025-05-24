#include <stdio.h>

int checkParentheses(char expression[]) {
    int count = 0;

    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(') {
            count++;
        } else if (expression[i] == ')') {
            count--;
            if (count < 0) {
                return 0;
            }
        }
    }

    if (count == 0){
        return 1;
    }
}

int main(){
    
    char expression[10];
    printf("Enter expression");
    scanf("%s",expression);

    if (checkParentheses(expression)) {
        printf("Expression has proper placement of parentheses.\n");

    } 
    
    else {
        printf("Expression does not have proper placement of parentheses.\n");
    }

    return 0;
}

//2nd method
int main(){
  char expression[50];
  scanf("%s",expression);
  int count_o = 0;
  int count_c = 0;
  for(int i =0;expression[i]!='\0';i++){
       if(expression[i] == '('){
       printf("%d",count_o);
       count_o++;
       
       }
       else if(expression[i] == ')' && count_o != count_c){
       count_c++;
       }
   }
   if(count_o == count_c){
      printf("Valid");
   }
   
   else{
    printf("Invalid");
   }
  return 0;
}