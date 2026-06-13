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
Node *reverse(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
void insertattail(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else 
    {
        tail->next = newNode;
        tail = newNode;
    }
}
Node *add(Node *&first, Node *&second)
{
    int carry = 0;
    Node *anshead = NULL;
    Node *anstail = NULL;
    while (first != NULL || second != NULL || carry != 0)
    {
        int val1 = 0;
        if (first != NULL)
        {
            val1 = first->data;
        }
        int val2 = 0;
        if (second != NULL)
        {
            val2 = second->data;
        }
        int sum = carry + val1 + val2;
        int digit = sum % 10;
        insertattail(anshead, anstail, digit);
        carry = sum / 10;
        if (first != NULL)
        {
            first = first->next;
        }
        if (second != NULL)
        {
            second = second->next;
        }
    }
    return anshead;
}

int main()
{
    //  create a node
    Node *node1 = new Node(1);
    // head pointed to node1
    Node *head = node1;
    Node *tail = node1;
    print(head);
    insertatposition(head, tail, 1, 2);
    print(head);
    insertatposition(head, tail, 1, 5);
    print(head);
    insertatposition(head, tail, 4, 3);
    print(head);
    cout << "head=" << head->data << endl;
    cout << "tail=" << tail->data << endl;
    //  create a node
    Node *node2 = new Node(6);
    // head pointed to node1
    Node *head2 = node2;
    Node *tail2 = node2;
    print(head2);
    insertatposition(head2, tail2, 1, 11);
    print(head2);
    insertatposition(head2,tail2, 1, 5);
    print(head2);
    insertatposition(head2, tail2, 4, 4);
    print(head2);
    cout << "head=" << head2->data << endl;
    cout << "tail=" << tail2->data << endl;
    Node *first = reverse(head);
    Node *second = reverse(head2);
    Node *ans = add(first, second);
    ans = reverse(ans);
    print(ans);
}
