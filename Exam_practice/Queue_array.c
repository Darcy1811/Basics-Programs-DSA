#include <stdio.h>
#define N 5

int Queue[N];
int r=-1;
int f=-1;

int isEmpty(){
    if(f==r){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(){
    if(r==(N-1)){
        return 1;
    }
    else return 0;
}

void Enqueue(int x){
    if(isFull()){
        printf("Queue overflow");
    }
    else{
        r++;
        Queue[r]=x;
    }
}

int Dequeue(){
    int a;
    if(isEmpty()){
        printf("Queue underflow");
    }
    else{
        f++;
        a=Queue[f];
    }
    return a;
}
int main(){
    Enqueue(40);
    Enqueue(50);
    Enqueue(60);
    printf("%d\n", Dequeue());
    printf("%d", Dequeue());
    
    
       
return 0;
}