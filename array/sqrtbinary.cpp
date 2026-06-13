#include<iostream>
using namespace std;

long long int binarySearch(int n)
{
    int s=0;
    int e=n;
    long long int mid=s+(e-s)/2;
    long long int ans=-1;

    while(s<=e)
    {
        long long int square = mid*mid;
        if(square == n)
        {
           return mid;
        }
        if(square<n)
        {
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
        cout << "s: " << s << ", e: " << e << ", mid: " << mid << ", ans: " << ans << endl;
    }
    return ans;
}
double moreprecision (int n,int precision,int tempsol)
{
    double ans=tempsol;
    double factor=1;
    for(int i=0;i<precision;i++)
    {
        factor=factor/10;
        for(double j=0;j*j<n;j=j+factor)
        {
            ans=j;
        }
    }
    return ans;
}

int main()
{
    int n = 258;
    long long int result = binarySearch(n);
    cout << "The square root of " << n << " is " << result << endl;
    cout<<"answer is "<<moreprecision(n,3,result)<<endl;
    return 0;
}
