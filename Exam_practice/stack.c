#include <stdio.h>
struct stack{
    int top;
    int size;
    int arr[100];
};

typedef struct stack mstack;

void initialize(mstack *fs){
    fs->top=-1;
}

int isEmpty(mstack *fs){
    if(fs->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(mstack *fs){
    if(fs->top==99){
        return 1;
    }
    else{
        return 0;
    }
}

void push(mstack *fs, int val){
    if(isFull(fs)){
        printf("Stack overflow");
    }
    else{
        fs->top++;
        fs->arr[fs->top]=val;
    }
}

int pop(mstack *fs){
    if(isEmpty(fs)){
        printf("Stack underflow");
        return -1;
        }
    else{
        int a=fs->arr[fs->top];
        fs->top--;
        return a;
    }
    }


int main(){
    mstack s;
    initialize(&s);
    push(&s, 20);
    push(&s, 40);
    printf("%d", pop(&s));

    return 0;
}