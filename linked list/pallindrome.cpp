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

void deletenode(int position ,Node* &head,Node* &tail)
{
    if(position==1)
    {
        Node* temp=head;
        head =head ->next;
        temp->next=NULL;
        delete temp;
    }
    else
    {
        Node* curr=head;
        Node* prev=NULL;
        int cnt=1;
        while(cnt < position)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        if(curr->next==NULL)
        {
            tail=prev;
        }
        prev->next=curr->next;
        curr -> next=NULL;
        delete curr;
    }
}
Node* getmid(Node* head)
{
    Node* slow=head;
    Node* fast = head->next;
    while (fast!=NULL && fast->next!= NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
Node* reverse(Node* head)
{
    Node* curr=head;
    Node* prev=NULL;
    Node* next=NULL;
    while (curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
    
}
bool pallindrome(Node * head)
{
    if(head->next==NULL)
    {
        return true;
    }
    Node* middle=getmid(head);
    Node* temp=middle->next;
    middle->next=reverse(temp);
    Node* head1=head;
    Node* head2=middle->next;
    while (head2!=NULL)
    {
        if(head1->data!=head2->data)
        {
            return false;
        }
        head1=head1->next;
        head2=head2->next;

    }
    middle->next=reverse(temp);
    return true;
    
}

int main()
{
    //  create a node
    Node* node1=new Node(12);
    // head pointed to node1
    Node* head=node1;
    Node* tail=node1;
    print(head);
    insertatposition(head,tail,1,12);
    print(head);
    insertatposition(head,tail,1,15);
    print(head);
    insertatposition(head,tail,4,15);
    print(head);
    cout<<"head="<<head->data<<endl;
    cout<<"tail="<<tail->data<<endl;
    int ans=pallindrome(head);
    if(ans==0)
    {
        cout<<"not a pallindrome";
    }
    else
    {
        cout<<"a pallindrome";
    }
}


