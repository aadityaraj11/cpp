#include<iostream>
#include<stack>
using namespace std;

int main()
{
    // creation of stack
    stack<int>  stackname;

    // push opertaion 
    stackname.push(2);
    stackname.push(3);
    stackname.push(4);
    cout<<"the top element is "<<stackname.top()<<endl;
    // stackname.swap(3,4);
   // pop operation
    stackname.pop();
    stackname.pop();
    stackname.pop();

    cout<<" is stack empty"<<stackname.empty()<<endl;
    cout<<"the size of stack is "<<stackname.size();

}