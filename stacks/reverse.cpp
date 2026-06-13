#include<iostream>
#include<stack>
using namespace std;

void insert(stack<int> & s,int element)
{
    if(s.empty())
    {
        s.push(element);
        return ;
    }
    int num=s.top();
    s.pop();
    // recursive call 
    insert(s,element);
    s.push(num);
}
void reverse(stack<int> & s)
{
    if(s.empty())
    {
        return ;
    }
    int num= s.top();
    s.pop();
    reverse(s);
    insert(s,num);
}

int main()
{
    stack <int> s;
    s.push(2);
    s.push(65);
    s.push(7);
    s.push(4);
    insert(s,23);
    int num= s.top();
    cout<<"top is "<<num<<endl;
    reverse(s);
    num= s.top();
    cout<<"after call top element is "<<num<<endl;

}
