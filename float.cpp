#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    float x=3456.123f;
    double a=9.123456789;
    long double aa=999.123456789L;
    cout<<setprecision(19);
    cout<<"double a="<<a<<endl;


    cout<<"long double aa="<<aa<<endl;
    cout<<"float x="<<x<<endl;
    
    // cout<<numeric_limits<float>::digits10<<endl;
    return 0;
}
