#include<stdio.h>

void display(int arr[], int size) {
    for (int i = 0; i <= size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
   
   int array[20]={10,15,20,40,45,50,60,100,150,200};
   int lower_bound=0;
   int upper_bound=9;
   int length=(upper_bound - lower_bound)+1;

   //print all the integers which are multiple of 10
   for (int i =0;i<10;i++){
      if(array[i] % 10 == 0){
        printf("%d \n",array[i]);
       }
   }
   
   //insert elements
   int pos;
   int element;
   printf("Enter pos:");
   scanf("%d",&pos);
   printf("Enter element:");
   scanf("%d",&element);
   for(int i=upper_bound+1;i>pos;i--){
          array[i] = array[i-1];
    }

    array[pos-1]=element;
    upper_bound++;    
   
    display(array , upper_bound);
    
    //delete elements
    int pos1;
    int del_element;
    printf("Enter element to delete");
    scanf("%d", &del_element);
    for(int i = 0;i<=upper_bound;i++){
       if (del_element == array[i]){
            pos1 =i;
       }
    }

   if (pos1 != -1) {
        for(int i = pos1; i < upper_bound; i++) {
            array[i] = array[i + 1];
        }
        upper_bound--;
    } 
    
    else {
        printf("Element not found for deletion.\n");
    }
    display(array , upper_bound);  

    // Read 4 digits and form a number
    int digits[4];
    printf("Enter 4 digits: ");
    for (int i = 0; i < 4; i++) {
        scanf("%d", &digits[i]);
    }

    // Form a number using the entered digits
    int formedNumber = digits[0] * 1000 + digits[1] * 100 + digits[2] * 10 + digits[3];
    printf("Formed Number: %d\n", formedNumber);

   return 0;
     
}