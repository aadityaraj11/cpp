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
    s.push(num); //backtrack
}
int main()
{
    stack <int> s;
    s.push(2);
    s.push(65);
    s.push(7);
    s.push(4);
    insert(s,23);
}
