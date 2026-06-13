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
        cout<<"Memory is free for node with data "<< this->data << endl;
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

Node * uniquesortedlist(Node * head)
{
    if(head==NULL)
    {
        return NULL;
    }
    Node *curr=head;
    while(curr!=NULL)
    {
        if((curr->next !=NULL)  &&  curr->data==curr->next->data)
        {
            Node* next_next =curr->next->next;
            Node* nodetodelete=curr->next;
            delete(nodetodelete);
            curr->next=next_next;
        }
        else
        {
            curr=curr->next;
        }
    }
    return head;
}

int main()
{
    //  create a node
    Node* node1=new Node(10);
    // head pointed to node1
    Node* head=node1;
    Node* tail=node1;
    print(head);
    insertatposition(head,tail,2,12);
    print(head);
    insertatposition(head,tail,3,15);
    print(head);
    insertatposition(head,tail,4,22);
    insertatposition(head,tail,3,15);
    insertatposition(head,tail,2,12);
    print(head);
    cout<<"head="<<head->data<<endl;
    cout<<"tail="<<tail->data<<endl;
    Node* head1=uniquesortedlist(head);
    print(head1);
    cout<<"head="<<head1->data<<endl;
    delete head; // delete the head of the list when you're done with it
    return 0;
}

// #include<iostream>
// using namespace std;


// class Node{
//     public:
//     int data;
//     Node* next;

//     // constructor
//     Node(int data)
//     {
//         this -> data= data;
//         this ->next=NULL;

//     }

//     // destructor
//     ~Node()
//     {
//         int value=this ->data;
//         // memory free
//         if(this ->next !=NULL)
//         {
//             delete next ;
//             this ->next = NULL;             
//         }
//         cout<<"Memory is free for node with data "<< value << endl;
//     }
// };

// void print (Node* &head)
// {
//     Node* temp=head;
//     while(temp!=NULL)
//     {
//         cout<<temp->data<<" ";
//         temp=temp->next;
//     }
//     cout<<endl;
// }

// void insertathead(Node *&head, int d)
// {
//     Node *temp = new Node(d);
//     temp->next = head;
//     head = temp;
// }

// void insertatposition(Node* & head,Node* & tail,int position,int d)
// {
//     if(position==1)
//     {
//         insertathead(head,d);
//         return;
//     }
//     Node* temp=head;
//     int cnt =1;
//     while(cnt<position-1)
//     {
//         temp=temp->next;
//         cnt++;
//     }

//     // creating a node 
//     Node* nodetoinsert=new Node(d);
//     nodetoinsert->next = temp->next;
//     temp->next=nodetoinsert;
//     if(nodetoinsert->next == NULL)
//     {
//         tail=nodetoinsert;
//     }

// } 

// void deletenode(int position ,Node* &head,Node* &tail)
// {
//     if(position==1)
//     {
//         Node* temp=head;
//         head =head ->next;
//         temp->next=NULL;
//         delete temp;
//     }
//     else
//     {
//         Node* curr=head;
//         Node* prev=NULL;
//         int cnt=1;
//         while(cnt < position)
//         {
//             prev=curr;
//             curr=curr->next;
//             cnt++;
//         }
//         if(curr->next==NULL)
//         {
//             tail=prev;
//         }
//         prev->next=curr->next;
//         curr -> next=NULL;
//         delete curr;
//     }
// }
// Node * uniquesortedlist(Node * head,Node* tail)
// {
//     if(head==NULL)
//     {
//         return NULL;
//     }
//     Node *curr=head;
//     while(curr!=NULL)
//     {
//         if((curr->next !=NULL)  &&  curr->data==curr->next->data)
//         {
//             Node* next_next =curr->next->next;
//             Node* nodetodelete=curr->next;
//             delete(nodetodelete);
//             curr->next=next_next;
//         }
//         else
//         {
//             curr=curr->next;
//         }
//     }
//     return head;
// }

// int main()
// {
//     //  create a node
//     Node* node1=new Node(10);
//     // head pointed to node1
//     Node* head=node1;
//     Node* tail=node1;
//     print(head);
//     insertatposition(head,tail,2,12);
//     print(head);
//     insertatposition(head,tail,3,15);
//     print(head);
//     insertatposition(head,tail,4,22);
//     insertatposition(head,tail,3,15);
//     insertatposition(head,tail,2,12);
//     print(head);
//     cout<<"head="<<head->data<<endl;
//     cout<<"tail="<<tail->data<<endl;
//     Node* head1=uniquesortedlist(head,tail);
//     print(head1);
//     cout<<"head="<<head1->data<<endl;
// }

