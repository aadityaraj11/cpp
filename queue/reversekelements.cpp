#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void reversek (queue<int> &q,int k)
{  
    stack<int> s;
    for(int i=0;i<k;i++)
    {
        int val=q.front();
        q.pop();
        s.push(val);
    }
    while(!s.empty())
    {
        int element=s.top();
        s.pop();
        q.push(element);
    }
    int t=q.size()-k;
    while(t--)
    {
        int value=q.front();
        q.pop();
        q.push(value);
    }
    return;
}
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(4);
    q.push(7);
    q.push(8);
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    reversek(q,4);
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    
}