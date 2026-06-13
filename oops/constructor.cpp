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
    cout<<"simple constructor called"<<endl;
    name=new char[100];
    }
    // paramerterised constructor .
    hero (int health )
    {
        this->health=health;
    }
    // copy constructor 
    hero(hero &temp)
    {
        char *ch=new char[strlen(temp.name)+1];
        strcpy(ch,temp.name);
        this->name=ch;
        cout<<endl<<"copy construstor called"<<endl;
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
        cout<<endl;
        cout<<"[Name:"<<this->name<<"'";
        cout<<"health:"<<this->health<<"'";
        cout<<"level"<<this->level<<"]";
    }
    void setname(char name[])
    {
        strcpy(this->name,name);
    }
    static int random ()
    {
        timetocomplete;
        //cout<< health<<endl; // this line will give error as health is not static member 
    }
    // destrutor 
    ~hero()
    {
        cout<<"simple destructor called"<<endl;

    }
    
};
int hero::timetocomplete =5;
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
    // ramesh=suresh;
    // ramesh.print();
    // suresh.print();
    // // in static allocation destructor called automatically 
    //  while in dynamic allocation we have to call it manually
    //  eg.
    // stastically 
    // hero a;
    // dynamically
    // hero *b=new hero();
    // calling destructor manually for dynamic allocation 
   
    // delete b ;

    //  cout<<hero::random()<<endl;
     cout<<hero::timetocomplete<<endl;
    hero a;
    cout<<a.timetocomplete<<endl;
    // hero b;
    // cout<<a.timetocomplete<<endl;
    // cout<<b.timetocomplete<<endl;

    
return 0;
}