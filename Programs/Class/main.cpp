#include <stdlib.h>
#include <stdio.h>
int main()
{
    int a;
    char grade;
    printf("enter marks \n");
    scanf("%d", &a);
    if(a<=39)
        grade = 'F';
    else if(a<=49)
        grade = 'e';
    else if(a<=59)
        grade = 'd';
    else if(a<=69)
        grade = 'c';
    else if(a<=79)
        grade = 'b';
    else if(a<=89)
        grade = 'a';
    else if(a<=100)
        grade = 'o';
        
     printf("Grade : %c \n", grade);
   
}