#include <stdio.h>
#include <string.h>

struct book{
	int num;
	char author[20];
	char title[20];
	int flag;	
};
void display_info(struct book x);
void display_info(struct book x){
int i=0;
	printf("Number of Book%d is: %d ", i+1, x.num);
	printf("\n");
	printf("Author of Book%d is: %s ", i+1, x.author);
	printf("\n");
	printf("Title of Book%d is: %s ", i+1, x.title);
	printf("\n");	
	if(x.flag==0){
		printf("Book is not issued");
	}
	else{
		printf("Book is issued");
	}
	
}

void display_title(struct book x);
void display_total(struct book x);

int main(){
struct book B[3];
int count;
	for(int i=0; i<3; i++){
		printf("Enter number of book\n");
		scanf("%d", &B[i].num);
		printf("Enter author of the book\n");
		scanf("%s", B[i].author);
		printf("Enter title of the book\n");
		scanf("%s", B[i].title);
		int flag;
		printf("Enter whther book is issued(1) or not(0)\n");
		scanf("%d",&B[i].flag); 
		printf("\n");
		display_info(B[i]);	
		printf("\n");			
	}
		
	char a_check[20];
	printf("Enter the name of the author you want to check.");
	scanf("%s", a_check); 
	for(int i=0; i<3; i++){
	int val =strcmp(B[i].author, a_check);
	if(val==0){
	printf("%s", B[i].title);
	}
	else{
	printf("Book not found");
	}
	}
	
	char t_check[20];
	printf("Enter the name of the title you want to check.");
	scanf("%s", t_check); 
	for(int i=0; i<3; i++){
	int value= strcmp(B[i].title, t_check);
	if(value==0){
	printf("%s", B[i].title);
	}
	else{
	printf("Book not found");
	}
	break;
	}

	printf("\n Total number of books is 3");

\
	
return 0;
}

