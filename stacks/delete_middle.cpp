#include<iostream>
#include<stack>
using namespace std;

void middlenote(stack<int> &s,int count,int size)
{
    if(count==size/2)
    {
        s.pop();
        return;
    }
    int i=1;
    int num=s.top();
    // cout<<"call "<<i++<<"th deleting"<<num<<endl;;
    s.pop();
    // recusive call
    middlenote(s,count+1,size);
    s.push(num);
}

int main()
{
    stack <int> s;
    s.push(2);
    s.push(65);
    s.push(7);
    s.push(4);
    int count =0;    
    int size=s.size();
    middlenote(s,count,size);
    return 0;
}

