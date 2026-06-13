#include<iostream>
using namespace std;
int main()
{
    unsigned short ushort_int=56;
    signed short signed_short= -6;
    int a= 99916543;
    long int long_int=456789;
    long long int ll_int=9991654321;
    

    cout<<"sizeof short int"<<sizeof(short int)<<endl;
    cout<<"size of int"<<sizeof(int)<<endl;
    cout<<"long int"<<sizeof(long_int)<<endl;
    cout<<"long long int value:"<<sizeof(long long)<<endl;

    cout<<"unsigned short int:"<<ushort_int<<endl;
    cout<<"signed short int"<<signed_short<<endl;
    cout<<"long int"<<long_int<<endl;
    cout<<"long long int value:"<<ll_int<<endl;
    cout<<"a"<<a<<endl;
    return 0;

}