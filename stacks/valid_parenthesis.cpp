#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack <char> s;
    string str="(({}))";
    for(int i=0;i<str.length();i++)
    {
        char ch=str[i];
        if(ch=='(' || ch=='{'||ch=='[')
        {
            s.push(ch);
        }
        else
        {
            if(!s.empty())
            {
                char top=s.top();
                if((ch==')' && top=='(') || (ch=='}'&& top=='{') || (ch==']' && top=='['))
                {  
                    s.pop();
                }
                else
                {
                    cout<<"not a valid parenthesis"<<endl;
                    return 0;
                }
            }
            else
            {
                cout<<"not a valid parenthesis"<<endl;
                return 0;
            }


        }
    }
    if(s.empty())
    {
        cout<<"yes a parenthesis"<<endl;
    }
    else
    {
        cout<<"not a valid parenthesis"<<endl;
    }
    return 0;
}