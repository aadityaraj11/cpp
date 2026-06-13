#include<iostream>
using namespace std;

bool issorted(int arr[],int size)
{
    // base case
    if (size==0 || size==1)
    {
        return true;
    }
    if(arr[0]>arr[1])
    {
        return false;
    }
    else
    {
        bool remainingpart=issorted(arr+1,size-1);
        return remainingpart;
    }
}
int main()
{
    int arr[5]={2,4,7,9,9};
    int size=5;
    bool ans =issorted(arr,size);
    if(ans)
    {
        cout<<"araay is sorted ";

    }
    else{
        cout<<"array not sorted";
    }
return 0;
}