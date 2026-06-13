#include<iostream>
using namespace std;

typedef struct employee
{
    // data
    int e_id;
    char favchar;
    float salary;
} ep;
int main()
{
    ep harry;
    ep shubham;
    ep rohan;
    harry.e_id=1;
    harry.salary=120000000;
    harry.favchar='c';
    cout<<"id:"<<harry.e_id<<endl;
    cout<<"salary:"<<harry.salary<<endl;
    cout<<"favchar:"<<harry.favchar;
    shubham.e_id=2;
    shubham.favchar='s';
    shubham.salary=1200;
    cout<<" shubham id:"<<shubham.e_id<<endl;
    cout<<"salary:"<<shubham.salary<<endl;
    cout<<"favchar:"<<shubham.favchar;
    rohan.e_id=3;
    rohan.favchar='r';
    rohan.salary=00000;
    cout<<" rohan id:"<<rohan.e_id<<endl;
    cout<<"salary:"<<rohan.salary<<endl;
    cout<<"favchar:"<<rohan.favchar;
return 0;

}