#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertathead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertatposition(Node *&head, Node *&tail, int position, int d)
{
    if (position == 1)
    {
        insertathead(head, d);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // creating a node
    Node *nodetoinsert = new Node(d);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
    if (nodetoinsert->next == NULL)
    {
        tail = nodetoinsert;
    }
}
Node *kreverse(Node *head, int k)
{
    // base case
    if (head == NULL)
    {
        return NULL;
    }
    // step1: reverse first k nodes
    Node *next = NULL;
    Node *curr = head;
    Node *prev = NULL;
    int count = 0;

    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    // step2: recusion call
    if (next != NULL)
    {
        head->next = kreverse(next, k);
    }
    return prev;
}
int main()
{
    //  create a node
    Node *node1 = new Node(10);
    // head pointed to node1
    Node *head = node1;
    Node *tail = node1;
    print(head);
    insertatposition(head, tail, 1, 12);
    print(head);
    insertatposition(head, tail, 1, 15);
    print(head);
    insertatposition(head, tail, 4, 22);
    print(head);
    cout << "head=" << head->data << endl;
    cout << "tail=" << tail->data << endl;
    cout << "Enter the value of k" << endl;
    int k;
    cin >> k;
    Node* newhead=kreverse(head, k); //function call
    print(newhead);
    cout << "head=" << newhead->data << endl;
    cout << "tail=" << tail->data << endl;
}
/*
Node* reverse(Node* head,int k)
{
    // base case
    if(head==NULL)
    {
        return NULL;
    }
    Node* curr=head;
    Node* prev=NULL;
    Node* forward=NULL;
    int count=0;
    while(curr!=NULL && count < k)
    {
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        count++;
    }
    if(forward!=NULL)
    {
        head->next=reverse(forward,k);
    }
    return  prev;
}
*/