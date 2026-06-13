#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char v[100]="abra ka dabra";
    int c=0;
    cout<<v<<endl;
    cout<<sizeof(v)<<endl;
    cout<<strlen(v)<<endl;
    for(int i=0;i<sizeof(v);i++)
    {
        if(v[i]!='\0')        
        {
            c++;
        }
    }
    cout<<"the value of c is:"<<c;
return 0;
}