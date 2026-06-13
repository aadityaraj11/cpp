#include<iostream>
using namespace std;
int main()
{
    char ch;
    cout<<"Enter a charcater"<<endl;
    cin>>ch;
    int cah=ch;
    if ((cah>47) && (cah<58))
    {
        cout<<"You have entered a numeric character";
    }
    else if((cah>64) &&(cah<91))
    {
        cout<<"You have entered a uppercase";
    }
    else if((cah>96) &&(cah<123))
    {
        cout<<"You have entered a lowercase";
    }
    else
    {
        cout<<"You have entered a special character";
    }

    
    return 0;
}