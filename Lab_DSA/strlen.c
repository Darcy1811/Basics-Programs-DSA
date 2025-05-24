#include <stdio.h>
int str_len(char x[]);

int str_len(char x[])
{
    int count = 0, i=0;
    while (x[i] != '\0')
    {
        count++;
    }
    return count;
}

int main()
{
    char string[50];
    printf("Enter your name: ");
    gets(string);
    str_len(string);
    printf("The length of the string is: %d ", str_len(string));

    return 0;
}