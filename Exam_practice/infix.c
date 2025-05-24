#include <stdio.h>
#include <stdlib.h>

struct stack{
    int top;
    int size;
    char *arr;
};

int isEmpty(struct stack *fs){
    if(fs->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack *fs){
    if(fs->top==99){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack *fs, char val){
    if(isFull(fs)){
        printf("Stack overflow");
    }
    else{
        fs->top++;
        fs->arr[fs->top]=val;
    }
}

char pop(struct stack *fs){
    if(isEmpty(fs)){
        printf("Stack underflow");
        return -1;
        }
    else{
        char a=fs->arr[fs->top];
        fs->top--;
        return a;
    }
    }

    int isOperator(char x){
            if(x=='*' || x=='/' || x=='+' || x=='-'){
                return 1;
            
        }
        else{
            return 0;
        }
    }

    int precedence(char x){
            if((x=='*') || (x=='/')){
                return 3;
            }
            else if((x=='+') || (x=='-')){
                return 2;
            }
            else{
                return 0;
            }
    

        }

    char stackTop(struct stack *fs){
        char a=fs->arr[fs->top];
        return a;
    }

    void postfix(char infix[100]){
        struct stack *s=(struct stack*)malloc(sizeof(struct stack));
        s->top=-1;
        s->size=100;
        s->arr=(char*)malloc(s->size*sizeof(char));
        char postfix[100];
        int i=0;
        int j=0;
        while(infix[i]!='\0'){
            if(!isOperator(infix[i])){
                postfix[j]=infix[i];
                i++;
                j++;
            }
            else{
                if(precedence(infix[i])>precedence(stackTop(s))){
                    push(s, infix[i]);
                    i++;
                }
                else{
                    postfix[j]=pop(s);
                    j++;
                }
            }
        }
            while(!isEmpty(s)){
                    postfix[j]=pop(s);
                    j++;
                }
                postfix[j]='\0';
    
    for (int k = 0; postfix[k]!='\0' ; k++)
    {
        printf("%c", postfix[k]);
    }
               
    }
    




int main(){
    char infix[100]="2+3*6-20/2";

  postfix(infix);

    

    return 0;
}