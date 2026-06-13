#include<iostream>
using namespace std;
int main()
{
    float x=10.5;
    float y=12.5;
    float z=true+x+false+y;
    cout<<sizeof(bool)<<endl;
    if((x<y)==true)
    {
        cout<<"x is lesser than y\n";
    }
    else
    {
        cout<<"y is lesser than x\n";
    }
    return 0;
}