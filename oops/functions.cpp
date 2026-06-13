#include<iostream>
#include<string.h>
using namespace std;
class hero
{
    int health;
    public:
    char *name;
    char level;
    hero()
    {
        cout<<"simple construtor called"<<endl;
    }
    hero (int health)
    {
        this->health=health;
    }
    hero(int health,char level)
    {
        this->level=health;
        this->level=level;
    }
    hero(hero & temp)
    {
        cout<<endl<<"copy constructor called"<<endl;
        this->health=temp.health;
        this->level=temp.level;

    }
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
        
        cout<<"health:"<<this->health<<endl;
        cout<<"level"<<this->level<<endl;
    }
    void setname(char name[])
    {
        strcpy(this->name,name);
    }
};
int main()
{
    // hero ramesh;
    // ramesh.sethealth(12);
    // ramesh.setlevel('d');
    // char name[7]="babbar";
    // ramesh.setname(name);
    // ramesh.print();
    // // use default copy constructor 
    // hero suresh(ramesh);
    // suresh.print();
    // ramesh.name[0]='G';
    // // this is shallow copy where the adress of name is same thats
    // //  why if you will change in one other will change automatically
    // // here cpoy is not generated 
    // ramesh.print();
    // suresh.print();
    hero ramesh(10);
    cout<<"adress of ramesh "<<&ramesh<<endl;
    ramesh.gethealth();
    ramesh.print();
    hero suresh(5);
    suresh.gethealth();
    suresh.print();
    ramesh.print();
return 0;
}