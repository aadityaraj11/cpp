#include<stdio.h>
#define MAX 100
int main()
{
    char str[MAX];
    printf("Enter a string to compress");
    gets(str);
    //assuming 1st letter as current and count =1
    char current=str[0];
    int count=1;
    //Comaring with remaining charcaters
    for(int i=1;str[i]!='\0';i++)
    {
        if(str[i]==current)
        {
            count++;
        }
        else
        {
            printf("%c%d",current,count);
            current=str[i];
            count=1;
        }
    }
    printf("%c%d",current,count);
    return 0;
}