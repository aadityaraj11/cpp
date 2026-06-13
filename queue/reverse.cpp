#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void reverse (queue<int> &q)
{
    stack<int> s;
    while(!q.empty())
    {
        int element=q.front();
        q.pop();
        s.push(element);
    }
    while(!s.empty())
    {
        int element=s.top();  
        s.pop();
        q.push(element);
    }
    return;
}
void reverse1(queue<int> &q)
{
    if(q.empty())
    {
        return;
    }
    int element=q.front();
    q.pop();
    reverse1(q);
    q.push(element);
}
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(4);
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    // q.pop();
    // cout<<q.front()<<endl;
    // cout<<q.back()<<endl;
    // q.pop();
    // cout<<q.front()<<endl;
    // q.pop();
    // cout<<q.size()<<endl;
    // cout<<q.empty();
    reverse(q);
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    reverse1(q);
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
}