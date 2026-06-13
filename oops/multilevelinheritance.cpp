#include<iostream>
using namespace std;
class animal
{
    public:
    int age;
    int weight ;
    public:
    void speak()
    {
        cout<<"speaking "<<endl;

    }

};
class dog:public animal{

};
class germanshepherd:public dog{

};
int main()
{
   germanshepherd g;
   g.speak();

return 0;
}
