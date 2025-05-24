#include <stdio.h>
#include <stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *p){
    if(p->r==p->f){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct queue *p){
    if((p->r+1)%p->size==p->f){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct queue *p, int val){
    if(isFull(p)){
        printf("Queue overflow");
    }
    else{
        p->r=(p->r+1)%p->size;
        p->arr[p->r]=val;
    }
}

int dequeue(struct queue *p){
    int a=-1;
    if(isEmpty(p)){
        printf("Queue underflow");
    }
    else{
        p->f=(p->f+1)%p->size;
        a=p->arr[p->f];
    }
        return a;
}
 
 int main(){
    struct queue *q=(struct queue*)malloc(sizeof(struct queue));
    q->f=q->r=0;
    q->size=4;
    q->arr=(int*)malloc(q->size*sizeof(int));
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printf("%d", dequeue(q));
    printf("%d", dequeue(q));
     enqueue(q, 10);
    enqueue(q, 20);
    

    return 0;
 }