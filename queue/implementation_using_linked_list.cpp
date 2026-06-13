#include<iostream>
using namespace std;
class queue{
    public:
    int data;
    queue *next;

    queue(int data)
    {
        this->data=data;
        this->next=NULL;
    }
    

    queue* head=NULL;
    void push(int element) 
    {
        queue *temp = new queue(element);
        if(head == NULL)
        {
            head = temp;
        }
        else 
        {
            queue *current = head;
            while(current->next != NULL) 
            {
                current = current->next;
            }
            current->next = temp;
        }
    }

    void pop()
    {

        if(head==NULL)
        {
            cout<<"queue is empty"<<endl;
            return;
        }
        queue* temp=head;
        head =head ->next;
        cout<<"deleting"<< temp->data<<endl;;
        delete temp;
        return;
    }
    int front()
    {
         if(head==NULL)
        {
            cout<<"queue is empty"<<endl;
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
    queue q(10);
    q.push(10);
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.push(20);
    cout << q.front() << endl;
    q.push(30);
    cout << q.front() << endl;
    q.pop();
    q.pop();
    cout<<q.front()<<endl; 

}