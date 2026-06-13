#include<iostream>
#include<map>
using namespace std;


class Node{
    public:
    int data;
    Node* next;

    // constructor
    Node(int data)
    {
        this -> data= data;
        this ->next=NULL;

    }

    // destructor
    ~Node()
    {
        int value=this ->data;
        // memory free
        if(this ->next !=NULL)
        {
            delete next ;
            this ->next = NULL;             
        }
        cout<<"Memory is free for node with data "<< value << endl;
    }
};

void print (Node* &head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void insertathead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertatposition(Node* & head,Node* & tail,int position,int d)
{
    if(position==1)
    {
        insertathead(head,d);
        return;
    }
    Node* temp=head;
    int cnt =1;
    while(cnt<position-1)
    {
        temp=temp->next;
        cnt++;
    }

    // creating a node 
    Node* nodetoinsert=new Node(d);
    nodetoinsert->next = temp->next;
    temp->next=nodetoinsert;
    if(nodetoinsert->next == NULL)
    {
        tail=nodetoinsert;
    }

}


Node* floyddetectloop(Node* head) 
{
    if(head==NULL)
    {
        return NULL;
    }
    Node* slow=head;
    Node* fast=head;
     while(slow!=NULL && fast!=NULL)
     {
        fast=fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
        }
        slow=slow->next;

        if(slow==fast)
        {
            // cout<<"present at "<<slow->data<<endl;  // this will be called by remove loop that's why is in comment 
            return slow;
        }

     }
     return NULL;
}


Node* getstartofloop(Node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    Node * intersection =floyddetectloop(head);
    Node* slow=head;

    while(slow!= intersection)
    {
        slow=slow->next;
        intersection=intersection->next;

    }
    return slow;
}
void removeloop(Node* head)
{
    if(head==NULL)
    {
        return;
    }
    Node* startofloop=getstartofloop(head);
    Node* temp=startofloop;
    while(temp->next != startofloop)
    {
        temp=temp->next;
    }
    temp->next=NULL;
}
int main()
{
    //  create a node
    Node* node1=new Node(10);
    // head pointed to node1
    Node* head=node1;
    Node* tail=node1;
    print(head);
    insertatposition(head,tail,1,12);
    print(head);
    insertatposition(head,tail,1,15);
    print(head);
    insertatposition(head,tail,4,22);
    print(head);
    head->next->next=head->next;                     //here you are making a loop
    cout<<"head="<<head->data<<endl;
    cout<<"tail="<<tail->data<<endl;
    if(floyddetectloop(head) != NULL)
    {
        cout<<"Cycle is present"<<endl;
    }
    else
    {
        cout<<"No Cycle"<<endl;
    }
    Node * ans=getstartofloop(head);
    if(ans==NULL)
    {
        cout<<"no loop is present"<<endl;
    }
    else
    { 
        cout<<"loop is present at "<<ans->data<<" position"<<endl;
    }
    removeloop(head);
    if(floyddetectloop(head) != NULL)
    {
        cout<<"Cycle is present"<<endl;
    }
    else
    {
        cout<<"No Cycle present "<<endl;
    }

}

