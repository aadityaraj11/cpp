#include<iostream>
using namespace std;
int main()
{
   int arr[8],i;
    for( i=0;i<8;i++)    
    {
        printf("Enter %dth element",i+1);
        scanf("%d",&arr[i]);
    }
    for(i=0;i<8;i++)    
    {
        printf("%d , ",arr[i]);
    }
    i=0;
    while(i<7)
    {
        swap(arr[i],arr[i+1]);
        i++;
        i++;
    }
     printf("after alternate swapping we have\n");
    for(int i=0;i<8;i++)    
    {
       printf("%d , ",arr[i]);
        
    }

return 0;
}