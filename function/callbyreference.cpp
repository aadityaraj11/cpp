#include<iostream>
using namespace std;
// will not swap
/*
int swap(int a,int b)
{
    int temp=a;
    a=b;
    b=temp;
    return 0;
}*/
//  will swap by reference
int swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
    return 0;
}

int main()
{
    int x=4,y=5;
    cout<<"the value of x is "<<x<<"and y is "<<y<<endl;
    swap(&x,&y);
    cout<<"The value of x is"<<x<<"and y is "<<y;
return 0;
}