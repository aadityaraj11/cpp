#include<iostream>
using namespace std;
class Employee{
    int id;
    static int count;

    public:
        void setdata(void){
            cout<<"Enter the id"<<endl;
            cin>>id;
            count++;
        }
        void getdata(void){
            cout<<"the id of "<<id<<"emplyee is"<<id<<"and number is "<<count<<endl;

        }
};    
    // COUNT IS A STATIC DATA MEMBER OF THIS CLASS.
int Employee ::count=1000;    //Default value is 0
int main()
{
        Employee harry,rohan,aadi;
        harry.setdata();
        harry.getdata();

        rohan.setdata();
        rohan.getdata();

        aadi.setdata();
        aadi.getdata();
        return 0;
}