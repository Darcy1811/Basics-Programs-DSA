#include <stdio.h>

struct Address{
	int House_no;
	int Street_no;
	char State[50];
};

struct Grade{
	int marks_1;
	int marks_2;
	int marks_3;
};

struct Student{
	char Name[50];
	int Roll_NO;
	struct Address A[3];
	struct Grade G[3];
};

void Sgpa(struct Student x){
	int sgpa;
	for(int i=0; i<3; i++){
	sgpa=(x.G[i].marks_1+x.G[i].marks_2+x.G[i].marks_3)/3;
	printf("Sgpa is: %d\n", sgpa);
	}
}

void display(struct Student x){
for(int i=0; i<3; i++){
	printf("The Name of the student is: %s\n", x.Name);
	printf("The Roll No of the student is: %d\n", x.Roll_NO);
	printf("The Adress of the student is: House No. %d, Street NO. %d, State %s\n", x.A[i].House_no, x.A[i].Street_no, x.A[i].State);
}
}

int main(){
struct Student S[3];
for(int i=0; i<3; i++){
	printf("Enter the name of Student1: ");
	scanf("%s", S[i].Name);
	printf("Enter Roll no. of Student1: ");
	scanf("%d", &S[i].Roll_NO);
	printf("Enter the House no of Student1: ");
	scanf("%d", &S[i].A[i].House_no );
	printf("Enter the Street mo of Student1: ");
	scanf("%d", &S[i].A[i].Street_no);
	printf("Enter the state of Student1: ");
	scanf("%s", S[i].A[i].State);
	printf("Enter the Marks 1 of Student1: ");
	scanf("%d", &S[i].G[i].marks_1);
	printf("Enter the Marks 2 of Student1: ");
	scanf("%d", &S[i].G[i].marks_2);
	printf("Enter the Marks 3 of Student1: ");
	scanf("%d", &S[i].G[i].marks_3);
display(S[i]);
printf("\n");
Sgpa(S[i]);
}


	
return 0;
}
