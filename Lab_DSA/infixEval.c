#include <stdio.h>
#include <ctype.h>

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

int precedence(char operator) {
        if (operator == '+' || operator == '-'){
            return 1;
        }
        else if (operator == '+' || operator == '-'){
            return 2;
        }
        else if(operator == '^'){
            return 3;
        }
        else if(operator == '('){
            return -1;
        }
}

int main(){
    mstack s;
    initialize(&s);
    char infix[50];
    char postfix[50];
    printf("Enter an infix expression");
    scanf("%s",&infix);
    int pi = 0;
    for(int i = 0; infix[i]!='\0';i++){
        if(isdigit(infix[i])){
            postfix[pi] = infix[i];
            pi++;
        }

        else if(infix[i] == '('){
            push(&s,infix[i]);
        }

        else if (infix[i] == ')') {
            while (!empty(&s) && s.items[s.top] != '(') {
                postfix[pi] = pop(&s);
                pi++;
            }
            if (!empty(&s) && s.items[s.top] == '(') {
                pop(&s);
            }
        }

        else{
            while (!empty(&s) && precedence(infix[i]) <= precedence(s.items[s.top])) {
                postfix[pi] = pop(&s);
                pi++;
            }
            push(&s, infix[i]);
        }

    }

    while (!empty(&s)) {
        postfix[pi] = pop(&s);
        pi++;
    }

    postfix[pi] = '\0'; 

    printf("postfix expression:%s",postfix);

    return 0;
}