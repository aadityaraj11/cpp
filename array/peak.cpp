#include<iostream>
using namespace std;
int peak(int arr[],int n)
{
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    while(s<=e)
    {
        if(arr[mid]<arr[mid+1])
        {
            s=mid+1;
        }
        else
        {
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return s;
}
int main()
{
    int arr[7]={3,4,5,6,7,2,1};
    cout<<"peak element is at index : "<<peak(arr,4);
    return 0;
}