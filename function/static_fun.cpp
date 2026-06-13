#include <iostream>
using namespace std;

int product(int a, int b)
{
    static int c = 0; //Being static, c retains its value between function calls and is only initialized once.
    c++;
    cout<<"The result of"<<a<<"*"<<b<<"+"<<c<<"is:";
    return a * b + c;
}

int main()
{
    int a, b;
    cout << "Enter two numbers\n";
    cin >> a >> b;
    cout<<product(a, b)<<endl;
return 0;
}