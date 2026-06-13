#include<iostream>
#include<stack>
using namespace std;

void sortedinsert(stack<int> &s,int num)
{
    if((s.empty())||((!s.empty()) && (s.top()<num)))
    {
        s.push(num);
        return;
    }
    int n=s.top();
    s.pop();
    sortedinsert(s,num);
    s.push(n);
}
void sort(stack<int> &s)
{
    // base case 
    if(s.empty())
    {
        return;
    }
    int num=s.top();
    s.pop();
    // recusive call 
    sort(s);
    sortedinsert(s,num);
}
int main()
{
    stack <int> s;
    s.push(2);
    s.push(65);
    s.push(4);
    s.push(7);
    int num=s.top();
    cout<<"before call= "<<num<<endl;
    sort(s);
    num=s.top();
    cout<<"after call="<<num<<endl;
}
