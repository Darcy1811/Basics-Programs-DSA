#include <stdio.h>
int main(){
int arr[5];
int n, *p;
n =20;
p = &n;
*p = *p +n; 
printf("%d, %d", *p, n);

for(int i=0;i<5;i++){
    printf("element - %d : ",i);
    scanf("%d",&arr[i]); 
}
p = arr;
for(int i=0; i<5; i++)
{ arr[i] = arr[i]-i;
printf("%d,  %d    ", i, arr[i]);
*(p+i) = arr[i] + 2*i;
printf("%d   ", *(p+i));
}
for(int i=0;i<5;i++){
printf("The values of array are %d\n”", arr[i]);
}
return 0;
}