#include <stdio.h>
#include <stdlib.h>
struct stack{
    int top;
    int size;
    int *arr
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

void push(struct stack *fs, int val){
    if(isFull(fs)){
        printf("Stack overflow");
    }
    else{
        fs->top++;
        fs->arr[fs->top]=val;
    }
}

int pop(struct stack *fs){
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

    void Enqueue(struct stack *s1,struct stack *s1, ){
        push(s1);
    }




int main(){
    struct stack *s1=(struct stack*)malloc(sizeof(struct stack));
    struct stack *s2=(struct stack*)malloc(sizeof(struct stack));
    s1->top=-1;
    s1->size=10;
    s1->arr=(int*)malloc(s1->size*sizeof(int));
    s2->top=-1;
    s2->size=10;
    s2->arr=(int*)malloc(s2->size*sizeof(int));

    

    return 0;
}