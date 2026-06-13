#include<iostream>
using namespace std;
int main()
{
  int a=3;
  int *b=&a;
  int **c=&b;
  cout<<"value of a:"<<a<<endl;
  cout<<"address of a"<<&a<<endl;
  cout<<"value of b/address of a "<<b<<endl;
  cout<<"deferencing value of b " <<*b<<endl;
  cout<<"address of b:"<<&b<<endl;
  cout<<"value of c/address of b:"<<c<<endl;
  cout<<"value of c"<<*c<<endl;
  cout<<"original value of c"<<**c<<endl;
  cout<<"address of c:"<<&c<<endl;
return 0;
}