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

void deletenode(int position, Node *&head, Node *&tail)
{
  if (position == 1)
  {
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
  }
  else
  {
    Node *curr = head;
    Node *prev = NULL;
    int cnt = 1;
    while (cnt < position)
    {
      prev = curr;
      curr = curr->next;
      cnt++;
    }
    if (curr->next == NULL)
    {
      tail = prev;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
  }
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

  deletenode(2, head, tail);
  print(head);
  cout << "head=" << head->data << endl;
  cout << "tail=" << tail->data << endl;

  deletenode(3, head, tail);
  print(head);
  cout << "head=" << head->data << endl;
  cout << "tail=" << tail->data << endl;
  deletenode(1, head, tail);
  print(head);
  cout << "head=" << head->data << endl;
  cout << "tail=" << tail->data << endl;
}

/////// this is code given by prabhat bhaiya

// #include<iostream>
// using namespace std;
// #define Log(x) cout<<x<<endl;

// class Node {
//   public:
//     int data;
//     Node *next;

//    Node *first=NULL;

//     void InsertFront(int x);
//     void display();

// };

//  void Node :: InsertFront(int x){
//   Node *t;
//   t = new Node;
//   t->data=x;
//   t->next = first;
//   first = t;
// }

// void Node :: display(){
//   Node *p= first;
//   while(p){
//     Log(p->data);
//     p = p->next;
//   }
// }

// int main(){
//   Node t;
//   t.InsertFront(5);
//   t.InsertFront(4);
//   t.InsertFront(3);
//   t.InsertFront(2);

//   t.display();
// }

/// this is cicular linked list code
// #include<iostream>
// using namespace std;
// #define Log(x) cout<<x<<endl;

// class Node{
//   public:
//   int data;
//   Node *next;
// };

// class LinkedList{
//   protected:
//     Node *head;
//   public:
//     LinkedList():head(NULL){}
//     LinkedList(int A[],int n);
//     ~LinkedList();
//     void Display() const;
// };

// LinkedList::LinkedList(int A[],int n){
//   Node *t,*last;
//   head = new Node;
//   head->data = A[0];
//   head->next = head;
//   last = head;

//   for(int i=1;i<n;i++){
//     t = new Node;
//     t->data = A[i];
//     t->next = last->next;
//     last->next = t;
//     last = t;
//   }
// }

// LinkedList::~LinkedList(){
//     Node* current = head;
//     Node* next = NULL;

//     do {
//         next = current->next;
//          printf("memory free for %d \n",current->data);
//         delete current;
//         current = next;
//     } while (current != head);
//     // head = nullptr;

//     // if (head == nullptr)
//     // {
//     //   return ;
//     // }
// }

// void LinkedList::Display() const{
//   Node *p = head;
//   do{
//     Log(p->data);
//     p = p->next;
//   }while(p!=head);
// }

// int main(){
//   int n = 6;
//   int A[n]= {1,2,3,4,5,6};
//   LinkedList l(A,n);
//   l.Display();

// }
