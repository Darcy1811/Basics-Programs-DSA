#include <stdio.h>
#include <stdlib.h>

struct my_stack{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct my_stack *p){
    if(p->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct my_stack *p){
    if(p->top==p->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct my_stack *p, char val){
    if(isFull(p)){
        printf("Stack overflow\n");
    }
    else{
        p->top++;
        p->arr[p->top]=val;
    }

}

char pop(struct my_stack *p){
    if(isEmpty(p)){
        printf("stack underflow\n");
        return -1;
    }
    else{
        char value=p->arr[p->top];
        p->top=p->top-1;
        return value;
    }
}

int parenthesisMatch(char *exp){
    struct my_stack *s=(struct my_stack *)malloc(sizeof(struct my_stack));
    s->size=100;
    s-> top=-1;
    s->arr=(char*)malloc(s->size*sizeof(char));
    for(int i=0; exp[i]!='\n'; i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[]'){
            push(s, exp[i]);
        }
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if(isEmpty(s)){
                return 0;
            }
            else{
                pop(s);
            }
        }
    }
    if(isEmpty(s)){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    char *expression;
    printf("Enter your expression:\n"); 
    scanf("%s", expression);
    if(parenthesisMatch(expression)){
        printf("Expression is valid");
    }
    else{
        printf("Expression is invalid");
    }
       
return 0;
}