#include<stdio.h>
#include<math.h>
int main()
{
    float x,sum=0,nume,demo,term;
    int i,degree;
    printf("Enter the dergre");
    scanf("%d",&degree);
    x=degree*(3.142/180);
    nume=x;
    demo=1;
    i=2;
    do 
    {
        term=nume/demo;
        nume=-nume*x*x;
        demo=demo*i*(i+1);
        sum=sum+term;
        i=i+2;
    }
    while(fabs(term)>=0.00001);
    printf("the sin of %d is %0.3f",degree,sum);
    return 0;


}