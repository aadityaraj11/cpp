#include<iostream>
using namespace std;
class A
{
    public:
    void sayhello()
    {
        cout<<"Hell love babbar"<<endl;
    }
    int sayhello(char name)
    {
        cout<<"Hello love babbar "<<endl;
        cout<<"called by 2nd function"<<endl;
        return 1;
    }
    void sayhello(string name )
    {
        cout<<"Hello "<<name<<endl;
        cout<<"called by 3rd function"<<endl;

    }
};

int main()
{
    A obj;
    obj.sayhello();
    obj.sayhello('A');
    obj.sayhello("AADITYA");


return 0;
}