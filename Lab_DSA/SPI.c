#include <stdio.h>
int main(){
int t_credits=0;
int t_credits2=0;
int sum;
int sum2;
int arr[5];
int credits[5];
float spi;
float spi2;
float cpi;
for(int i=0; i<5; i++){
 printf("Enter grades in sub%d: ", i+1);
 scanf("%d", &arr[i]);
 }
 
for(int j=0; j<5; j++){
printf("enter credits of sub%d: ", j+1);
scanf("%d", &credits[j]);
t_credits=t_credits+ credits[j];
}
printf("total credits is%d", t_credits);
for(int k=0; k<5; k++){
sum+= arr[k]*credits[k];
}
printf("sum is%d", sum);

 spi= sum/t_credits;
printf("spi is %f ", spi);


for(int i=0; i<5; i++){
 printf("Enter grades in sub%d: ", i+1);
 scanf("%d", &arr[i]);
 }
 
for(int j=0; j<5; j++){
printf("sem 2enter credits of sub%d: ", j+1);
scanf("%d", &credits[j]);
t_credits2=t_credits2+ credits[j];
}
printf("total credits sem 2 is%d", t_credits2);
for(int k=0; k<5; k++){
sum2+= arr[k]*credits[k];
}
printf("sum sem 2 is%d", sum2);

 spi2= sum/t_credits;
printf("spi of sem 2 is %f ", spi2);

 
  cpi= (spi+spi2)/2;
 printf("cpi is %f", cpi);
 return 0;
 }