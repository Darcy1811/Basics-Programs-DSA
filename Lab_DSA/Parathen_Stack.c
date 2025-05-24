#include <stdio.h>

struct my_stack_def{
    int top;
    int items[100];
};  
typedef struct my_stack_def mstack;

void initialize(mstack *fs){
    fs->top=-1;
}

int empty(mstack *fs){
   if (fs->top == -1){
    return 1;
   }
   
   else{
     return 0;
   }
}

int full(mstack *fs){
  if(fs->top == 99){
    return 1;
  }
 
  else{
   return 0;
  }
}

void push(mstack *fs,int i){
  if(!full(fs)){
     fs->top = fs->top+1;
     fs->items[fs->top] = i;
   
  }
}

int pop(mstack *fs){
  if(!empty(fs)){
     return(fs->items[fs->top--]);
  }
}

int main(){

    mstack s;
    initialize(&s);
    char expression[20];
    printf("Enter expression");
    scanf("%s",expression);
    
    int check = 1;
    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(') {
            push(&s, expression[i]);
        } 
        else if (expression[i] == ')') {
            if (empty(&s)) {
                printf("Unmatched closing parenthesis\n");
                check = 0;
                break;
            }            
            else {
                char bracket = pop(&s);
                if ((expression[i] == ')' && bracket != '(')) {
                    printf("Mismatched opening and closing parentheses\n");
                    check = 0;
                    break;
                }
            }
        }
    }

    if(check && empty(&s)){
        printf("The expression is balanced");
    }
    else{
        printf("No closing bracket");
    }

    return 0;
}