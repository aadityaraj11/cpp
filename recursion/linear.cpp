#include<iostream>
using namespace std;
int linearsearch(int *arr,int size,int key)
{
    // base case
    if(size==0)
    {
        return false;
    }
    if(arr[0]==key)
    {
        return true;
    }
    else
    {
        bool remaingpart=linearsearch(arr+1,size-1,key);
        return remaingpart;
    }
}
int main()
{
     int arr[5]={2,4,7,9,9};
    int size=5;
    int key=1;
    bool ans=linearsearch(arr,size,key);

    if(ans)
    {
        cout<<"present";
    }
    else{
        cout<<"absent";
    }
return 0;
}