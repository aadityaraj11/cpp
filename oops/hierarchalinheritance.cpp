#include<iostream>
using namespace std;
// hierarchical inheritance 
class A 
{
    public:
    void func1()
    {
        cout<<"Inside function A "<<endl;
    }
};
class B
{
    public:
    void func2()
    {
        cout<<"Inside function B "<<endl;
    }
} ;
class C:public A 
{
    public:
    void func3()
    {
        cout<<"Inside function C "<<endl;
    }
};
#include<iostream>
using namespace std;
int main()
{
    A obj1;
    obj1.func1();
    B obj2;
    // obj2.func1(); this line wont work 
    // bcz class B obj has not access of func 1 of class A 
    obj2.func2();
    C obj3;
    obj3.func1();
    // obj3.func2(); this line wont work bcz 
    //  class C has access of class  A 
    //  class C has not access of func 2 of class b 
    obj3.func3(); // this line will work 
return 0;
}