// #include <stdio.h>

// int main() {
//     int n = 4; // The maximum number in the pattern
//     int size = n * 2 - 1; // Calculate the size of the pattern
//     int i, j;
    
//     // Generate the pattern
//     for(i = 0; i < size; i++) {
//         for(j = 0; j < size; j++) {
//             // Determine the minimum distance to the border
//             int minDistance = i < j ? i : j;
//             minDistance = minDistance < size - i ? minDistance : size - i - 1;
//             minDistance = minDistance < size - j - 1 ? minDistance : size - j - 1;
        
//             // Print the value based on the minimum distance
//             printf("%d ", n - minDistance);
//         }
//         printf("\n");
//     }
    
//     return 0;
// }
#include<stdio.h>
int main()
{
    int n,i,j;
    printf("Enter a number\n");
    scanf("%d",&n);
    for(i=n;i>=1;i--)
    {
        for(j=n;j>i;j--)
        {
            printf("%d ",j);
        }
        for(j=1;j<=2*i-1;j++)
        {
            printf("%d ",i);
        }
        for(j=i+1;j<=n;j++)
        {
            printf("%d ",j);
        }
        printf("\n");
    }
    for(i=1;i<n;i++)
    {
        for(j=n;j>i;j--)
        {
            printf("%d ",j);
        }
        for(j=1;j<=2*i-1;j++)
        {
            printf("%d ",i+1);
        }
        for(j=i+1;j<=n;j++)
        {
            printf("%d ",j);
        }
        printf("\n");
    }
}