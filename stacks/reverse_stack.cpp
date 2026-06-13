// here we have used concept of stacks of first in last out concept to reverse string 


#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string str = "babbar";

    stack<char> s;

    char ch;
    for (int i = 0; i < str.length(); i++)
    {
        ch = str[i];
        s.push(ch);
    }

    string ans = "";
    while (!s.empty())
    {
        ch = s.top();
        ans.push_back(ch);
        s.pop();
    }

    cout << "reverse string is " << ans << endl;
}


