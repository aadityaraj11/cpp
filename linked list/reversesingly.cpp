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
Node* reverse2(Node*    head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node* chotahead=reverse2(head->next);
    head->next->next=head;
    head->next=NULL;
    return chotahead;

}
void reverse1(Node* &head,Node* curr,Node* prev)
{
    // base case
    if(curr==NULL)
    {
        head=prev;
        return;
    }
    Node * forward =curr->next;
    reverse1(head,forward,curr);
    curr->next=prev;
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
    
    Node* curr=head;
    Node* prev=NULL;
    reverse1(head,curr,prev); // approacch 1 function call
    print(head);
    cout<<"head="<<head->data<<endl;
    cout<<"tail="<<tail->data<<endl;

    head = reverse2(head); //approach 2 function call
    print(head);
    cout<<"head="<<head->data<<endl;
    cout<<"tail="<<tail->data<<endl;

    deletenode(2,head,tail);
    print(head);
    cout<<"head="<<head->data<<endl;
    cout<<"tail="<<tail->data<<endl;

    deletenode(3,head,tail);
    print(head);
    cout<<"head="<<head->data<<endl;
    cout<<"tail="<<tail->data<<endl;
    deletenode(1,head,tail);
    print(head);
    cout<<"head="<<head->data<<endl;
    cout<<"tail="<<tail->data<<endl;
    
    // Node* curr=head; /* here we need to update the head and then call the reverse function otherwise it will call */ 
    // Node* prev=NULL;  /* reverse function with old head as head = curr is declared above */
    reverse1(head,curr,prev); // approacch 1 function call
    print(head);
    cout<<"head="<<head->data<<endl;
    cout<<"tail="<<tail->data<<endl;

    head = reverse2(head); //approach 2 function call
    print(head);
    cout<<"head="<<head->data<<endl;
    cout<<"tail="<<tail->data<<endl;

}

