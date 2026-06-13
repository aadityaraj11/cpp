#include<stdio.h>
int main()
{
    int num=8;
    int flag=(num % 2==0?1:0);
    if (flag==1)
        printf("Even");
    else   
        printf("odd");

return 0;
}