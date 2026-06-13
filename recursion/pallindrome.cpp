#include<iostream>
#include<string.h>
using namespace std;
bool check(char chr[],int s,int e,int mid)
{
    if(mid>e)
    {
        return true;
    }
    
    if(chr[s]!=chr[e])
    {
        return false;
    }
    else
    {
        return check(chr,s+1,e-1,mid);
    }
}

int main()
{
    char chr[10]={"abccba"};
    int s=0;
    int e=strlen(chr);
    int mid=s+(e-s)/2;
    bool ans = check(chr,s,e-1,mid);
    if(ans==0)
    {
        cout<<"not a pallindrome"<<endl;
    }
    else
    {
        cout<<"A pallindrome"<<endl;
    }
return 0;
}