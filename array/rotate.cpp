#include<iostream>
using namespace std;
  
int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int k=2;
    int arr2[10];
    for(int i=0;i<10;i++)
    {
        arr2[i]=arr[i];
    }
    for(int i=0;i<10;i++)
    {
        arr2[(i+k)%10]=arr[i];
    }
    for(int i=0;i<10;i++)
    {
        arr[i]=arr2[i];
    }
    cout<<"Rotated array is :"<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}