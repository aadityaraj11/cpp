#include<iostream>
#include<string.h>
using namespace std;
int reverse(char chr[],int s,int e)
{
    if(s>e)
    {
        return 0;
    }
    else
    {
        swap(chr[s],chr[e]);
        // cout<<"doing on "<<chr[s]<<" and "<<chr[e]<<endl;
        reverse(chr,s+1,e-1);
    }
}

int main()
{
    char chr[10]={"aaditya"};
    int s=0;
    int e=strlen(chr);
    cout<<"before"<<endl;
    printf("%s",chr);
    cout<<endl;
    reverse(chr,s,e-1);
    cout<<"after"<<endl;
    printf("%s",chr);
return 0;
}