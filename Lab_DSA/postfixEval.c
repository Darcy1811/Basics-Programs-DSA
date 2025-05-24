#include <stdio.h>
#include  <ctype.h>

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
  return -1;
}

int main(){
    mstack s;
    initialize(&s);
    char post[20];
    printf("Emter an postfix Expression");
    scanf("%s",post);
    
    int i,op1,op2;
    for(int i = 0;post[i]!='\0';i++){
      if(isdigit(post[i])){
        push(&s,post[i]-'0');
      }
      else{
        op2 = pop(&s);
        op1 = pop(&s);
      }    
     
      switch(post[i]){
          case'+':
            push(&s,op1+op2);
            break;
          case'-':
            push(&s,op1-op2);
            break;
          case'*':
            push(&s,op1*op2);
            break;
          case'/':
            push(&s,op1/op2);
            break;  
      }  
   }
   printf("result %d\n",pop(&s));
   return 0;
}