#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
// char * timeconversion(char *s)
int main()
{
    char s[100]={"11:11:11PM"};
    int hr=atoi(strtok(s, ":"));
    int min=atoi(strtok(NULL, ":"));
    int sec=atoi(strtok(NULL, ""));

    char ampm[3];
    ampm[0]=s[8];
    ampm[1]='M';
    char *time=malloc(128*sizeof(char));
    if(strcmp(ampm,"AM")==0 && hr==12)
    {
        sprintf(time,"00:%.2d:%.2d",min,sec);
    }
    else if(strcmp(ampm,"AM")==0)
    {
        sprintf(time,"%.2d:%.2d:%.2d",hr,min,sec);
    }
    else if(strcmp(ampm,"PM")==0)
    {
        if(hr!=12)
        {
            hr=hr+12;
        }
        sprintf(time,"%.2d:%.2d:%.2d",hr,min,sec);
    }
    return 0;
}