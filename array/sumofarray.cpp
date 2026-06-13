#include<stdio.h>
int main()
{
    int arr[20],sum=0;
    for(int i=0;i<5;i++)    
    {
        printf("Enter %dth element",i+1);
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<5;i++)
    {
        sum=sum+arr[i];
    }
    printf("SUM =%d",sum);
    return 0;
}