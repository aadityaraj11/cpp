  #include<iostream>
  using namespace std;
    int firstoccur(int arr[],int n, int key)
  {
    int s=0,e=n-1;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e)
    {
      if(arr[mid]==key)
      {
        ans=mid;
        e=mid-1;
      }
      else if(key>arr[mid])
      {
        s=mid+1;
      }
      else{
        e=mid-1;
      }
      mid=s+(e-s)/2;
    }
    return ans;
  }
  int lastoccur(int arr[],int n, int key)
  {
    int s=0,e=n-1;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e)
    {
      if(arr[mid]==key)
      {
        ans=mid;
        s=mid+1;
      }
      else if(key>arr[mid])
      {
        s=mid+1;
      }
      else{
        e=mid-1;
      }
      mid=s+(e-s)/2;
    }
    return ans;
  }
  int main()
  {
    int even[11]={1,2,3,3,3,3,3,3,3,5,6};
    int res1=firstoccur(even,11,3);
    int res2=lastoccur(even,11,3);
    cout<<"First occurence is at "<<res1;
    cout<<"\nLast occurence is at "<<res2;
    cout<<"\nTotal occurence are "<<(res2-res1)+1;
  return 0;
  }                                                              