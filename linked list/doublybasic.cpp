#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
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

void insertattail(Node *&tail, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertathead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
void insertatposition(Node *&tail, Node *&head, int position, int d)
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
    // inserting at last position
    if (temp->next == NULL)
    {
        insertattail(tail, d);
        return;
    }
    // creating a node for d
    Node *nodetoinsert = new Node(d);
    nodetoinsert->next = temp->next;
    temp->next->prev = nodetoinsert;
    temp->next = nodetoinsert;
    nodetoinsert->prev = temp;
}

void deletenode(int position, Node *&head,Node* &tail)
{
    // deleting first Node
    if (position == 1)
    {
        Node *temp = head;
        temp->next ->prev  = NULL;
        head = temp->next;
        temp->next = NULL ;
        delete temp;
    }
    else
    {
        // deleting any middle Node
        Node *curr = head;
        Node *prev = NULL ;

            int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if(curr->next==NULL)
        {
            tail=prev;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail=node1;
    print(head);
    insertathead(head, 11);
    print(head);
    insertatposition(tail, head, 2, 100);
    print(head);
    cout << "head=" << head->data<<endl;
    cout << "tail=" << tail->data << endl;
    insertattail(tail,200);
    print(head);
    cout << "head=" << head->data<<endl;
    cout << "tail=" << tail->data << endl;
    deletenode(3, head,tail);
    print(head);
    cout << "head=" << head->data<<endl;
    cout << "tail=" << tail->data << endl;
    deletenode(3, head,tail);
    print(head);
    cout << "head=" << head->data<<endl;
    cout << "tail=" << tail->data << endl;
    return 0;
}
