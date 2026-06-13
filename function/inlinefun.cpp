#include<iostream>
using namespace std;
inline int product(int a,int b)
{     
    // NOT RECOMMENDED TO USE BELOW LINES WITH INLINE FUNCTION.
    // STATIC INT C=0;THIS WILL BE EXECUTED ONCE.
    // C++;NEXT TIME IF FUNCTION RUN,THE VALUE OF C WILL BE RETAINED.
    
    
    return a*b;
 }
float money(int income,float factor=1.04)
{
    return income*factor;
}

int main()
{
    int a,b;
    float salary;
    cout<<"Enter two numbers"<<endl;;
    cin>>a>>b;
    cout<<"Result ="<<product(a,b)<<endl;
    cout<<"Enter your income"<<endl;
    cin>>salary;
    cout<<"IF YOUR INCOME IS "<<salary<<"RS IN YOUR ACCOUNT THEN YOU WILL RECIEVED "<<money(salary);
return 0;
}