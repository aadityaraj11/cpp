#include<iostream>
using namespace std;
int binarysearch(int *arr,int s,int e,int key)
{
    // element found
    if(s>e)
    {
        return false;
    }
    int mid=s+(e-s)/2;

    // element found
    if(arr[mid]==key)
    {
        return true;
    }
    if(arr[mid]<key)
    {
        return binarysearch(arr,mid+1,e,key);
    }
    else
    {
        return binarysearch(arr,s,mid-1,key);
    }
}
int main()
{
     int arr[5]={2,4,7,9,9};
    int size=5;
    int key=2;
    bool ans=binarysearch(arr,0,5,key);
    if(ans)
    {
        cout<<"present";
    }
    else
    cout<<"absent";
return 0;
}