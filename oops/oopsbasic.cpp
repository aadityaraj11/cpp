#include<iostream>
#include<string.h>
using namespace std;
class hero
{
    int health;
    public:
    char *name;
    char level;
    int gethealth()
    {
        return health;
    }
    char getlevel()
    {
        return level;
    }
    void sethealth(int h)
    {
        health=h;
    }
    void setlevel(char ch)
    {
        level=ch;
    }
    void print()
    {
        cout<<endl;
        cout<<"[Name:"<<this->name<<"'";
        cout<<"health:"<<this->health<<"'";
        cout<<"level"<<this->level<<"]";
    }
    void setname(char name[])
    {
        strcpy(this->name,name);
    }
};
int main()
{
    hero ramesh;
    ramesh.sethealth(12);
    ramesh.setlevel('d');
    char name[7]="babbar";
    ramesh.setname(name);
    ramesh.print();
    // use default copy constructor 
    hero suresh(ramesh);
    suresh.print();
    ramesh.name[0]='G';
    // this is shallow copy where the adress of name is same thats
    //  why if you will change in one other will change automatically
    // here cpoy is not generated 
    ramesh.print();
    suresh.print();
    
return 0;
}