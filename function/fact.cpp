#include<iostream>
using namespace std;
int fact(int n)
{     
    if(n==1)
    {   cout<<"1=";
        return 1;
    }
    else
    {
        cout<<n<<"x";
    return n*fact (n-1);
    }
}
int main()
{
    int n;
    cout<<"enter a number"<<endl;
    cin>>n;
    cout<<n<<"!=";
    cout<<fact(n)<<endl;
return 0;
}