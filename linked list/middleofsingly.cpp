#include<iostream>
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

Node * getmiddle(Node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    if(head->next->next==NULL)
    {
        return head->next;
    }
    Node * slow=head;
    Node* fast=head->next;
    while(fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
        }
        slow=slow->next;

    }
    return slow;
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
    cout<<"head="<<head->data<<endl;
    cout<<"tail="<<tail->data<<endl;
    Node* middle=getmiddle(head);
    cout<<"middle is "<<middle->data<<"at "<</*think later and write this code that how to find position of middle element */" "<<"position"<<endl;

}

