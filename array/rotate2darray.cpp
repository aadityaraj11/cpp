#include<iostream>
using namespace std;
int main()
{
    int a[3][3];
    int arr[3][3]={1,2,3,4,5,6,7,8,9};
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
    for(int j=0;j<=2;j++)
    {
        for(int i=2;i>=0;i--)
        {   
            // printf("%d\t",arr[i][j]);
            // a[j][i]=arr[i][j];
            a[j][2-i]=arr[i][j]; // Corrected line
        }
        printf("\n");
    }
    int p,q;
    p=q=0;
    printf("\nnew array\n");
    for(p=0;p<3;p++){
        for(q=0;q<3;q++){
            printf("%d\t",a[p][q]);
        }
        printf("\n");
    }
return 0;
}