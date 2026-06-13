#include<iostream>
using namespace std;
#define Log(x) cout<<x<<endl;

class Node {
  public:
    int data;
    Node *next;

   Node *first=NULL;

    void InsertFront(int x);
    void display();
    Node* sort(Node* head);
    Node* first1();

};

Node* Node::first1()
{
    Node* p=first;
    return p;
}

 void Node :: InsertFront(int x){
  Node *t;
  t = new Node;
  t->data=x;
  t->next = first;
  first = t;
}

void Node :: display(){
  Node *p= first;
  while(p){
    Log(p->data);
    p = p->next;
  }
}
Node* Node :: sort(Node* head)
{
    int zeroc=0;
    int onec=0;
    int twoc=0;
    Node* temp=first;
    while(temp!=NULL)
    {
        if(temp->data==0)
        {
            zeroc++;
        }
        else if(temp->data==1)
        {
            onec++;
        }
        else
        {
            twoc++;
        }
        temp=temp->next;
    }
    temp=first;
    while(temp!=NULL)
    {
        while(zeroc!=0)
        {
            temp->InsertFront(0);
            zeroc--;
            temp=temp->next;
        }
        while(onec!=0)
        {
            temp->InsertFront(1);
            onec--;
            temp=temp->next;
        }
        while(twoc!=0)
        {
            temp->InsertFront(2);
            twoc--;
            temp=temp->next;
        }
        
    }
    cout<<"After call"<<endl;
     temp= first;
  while(temp){
    Log(temp->data);
    temp = temp->next;
  }
}

int main(){
  Node t;
  t.InsertFront(2);
  t.InsertFront(2);
  t.InsertFront(0);
  t.InsertFront(1);
  t.InsertFront(1);
  t.display();
  Node* head=t.first1();
  t.sort(head);
}