/*#include <stdio.h>
#include <stdlib.h>
int main()
{
FILE *fptr1, *fptr2;
char filename[100], c;
printf("Enter the filename to open for reading \n");
scanf("%s", filename);
fptr1 = fopen(filename, "r");
if (fptr1 == NULL)
{
printf("Cannot open file %s \n", filename);
exit(0);
}
printf("Enter the filename to open for writing \n");
scanf("%s", filename);
fptr2 = fopen(filename, "w");
if (fptr2 == NULL)
{
printf("Cannot open file %s \n", filename);
exit(0);
}
c = fgetc(fptr1);
while (c != EOF)
{
fputc(c, fptr2);
c = fgetc(fptr1);
}
printf("\nContents copied to %s", filename);
fclose(fptr1);
fclose(fptr2);
return 0;
}*/
#include<stdio.h>
#include<string.h>
int main(){
char name1[20],name2[30];
printf("Enter name of 1st");
scanf("%s",name1);
printf("Enter 2nd name");
for(int i=0;i<6;i++)
{
    scanf("%c",&name2[i]);
}
printf("%s",name1);
for(int i=0;i<6;i++)
{
    printf("%c",name2[i]);
    // here only 4 char will be taken instead of 5 bcz last char will be  null charcater 
}
int res=strcmp(name1,name2);
if(res==0)
{
    printf("equal");
}
else
{
    printf("not equal");
}
return 0;
}