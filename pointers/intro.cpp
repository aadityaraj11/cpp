#include<iostream>
using namespace std;
int main()
{
    // int *p=0;
    // cout<<*p<<endl;
    int i=5;
    int *q=&i;
    cout<<"q=" q <<endl;
    cout<<"*q="*q<<endl;
    int *p=0;
    p=&i;
    cout<<"p="p<<endl;
    cout<<"*p="*p<<endl;
    // copying a pointer
    int *qa=p;
    cout<<p<<" - "<<qa<<endl;
    cout<<*p<<" - "<<*qa<<endl;
return 0;
}