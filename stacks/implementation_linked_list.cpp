#include<iostream>
using namespace std;
// class stack
// {
//     public:
//     int data;
//     stack *next;

//     stack(int data)
//     {
//         this->data=data;
//         this->next=NULL;
//     }
// };
//     stack* head=NULL;
// This code was written earlier the below code has written with help of chatgpt
class Stack {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* head;

public:
    Stack() : head(nullptr) {}
    void push(int element)
    {
        Node *temp=new Node(element);
        temp->next=head;
        head=temp;
    }
    void pop()
    {

        if(head==NULL)
        {
            cout<<"stack is empty"<<endl;
            return;
        }
        Node* temp=head;
        head =head ->next;
        temp->next=NULL;
        cout<<"deleting"<< temp->data<<endl;
        delete temp;
        return;
    }
    int top()
    {
         if(head==NULL)
        {
            cout<<"stack is empty"<<endl;
            return -1;
        }
        else
        {
        return head->data;
        }
    }
};
int main()
{
    Stack st;
    st.push(10);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.push(20);
    cout << st.top() << endl;
    st.push(30);
    cout << st.top() << endl;
    st.pop();
    st.pop();
    cout << st.top() << endl;
    return 0;
}