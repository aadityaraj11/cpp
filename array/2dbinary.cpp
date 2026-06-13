#include<iostream>
using namespace std;
int main()
{
    int arr[3][3]={1,2,3,4,5,6,7,8,9};
    int key=1;
    int start=0;
    int end=8;                                              // end=(row*col)-1;
    int mid=start+(end-start)/2;
    while(start<=end)
    {
        cout<<arr[mid/3][mid%3]<<endl;
        if(key==arr[mid/3][mid%3])
        {
            cout<<"element found at:"<<arr[mid/3][mid%3]<<endl;
            exit(0);
        }
        else if(key<arr[mid/3][mid%3])
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
        mid=start+(end-start)/2;
            cout<<"element not found";

    }
    // cout<<"element not found";

return 0;
}