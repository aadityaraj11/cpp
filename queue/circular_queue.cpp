#include<iostream>
// #include<queue>
using namespace std;
class queue
{   
    public:
        int *arr;
        int size;
        int rear;
        int front;
    queue(int size)
    {
        arr=new int (size);
        front=-1;
        rear=-1;
    }
    void push (int element)
    {
        if((front==0 && rear==size-1)||(rear==((front-1)%(size-1))))
        {
            cout<<"queue is full";
        }
        else if(front==-1)  //first element to push
        {
            front=rear=0;
            arr[rear]=element;
        }
        else if(rear==size-1 && front!=0)  // pop krte hue front aage aagya h to rear ab first index pr jayega
        {
            rear=0;
            arr[rear]=element;
        }
        else
        {
            rear++;
            arr[rear]=element;
        }
    }
    int pop()
    {
        if(front==-1)
        {
            cout<<"queue is empty";
            return 0;
        }
            int ans =arr[front];
            arr[front]=-1;
            if(front==rear)  //single element is present
            {
                front=rear=-1;
            }
            else if(front ==size-1)  //  front is at last index after pop it should go to next one
            {
                front =0;
            }
            else  // normal case pop
            {
                front++;
            }
            return ans;
    }
    int rfront()
    {
        if(front==-1)
        {
            cout<<"empty";
            return 0;
        }
        else
        {
            return arr[front];
        }
    }
    bool empty()
    {
        if(front==-1)
        {
            return true;

        }
        else{
            return false;
        }
    }
};

int main()
{
    queue q(10);
    q.push(6);
    q.push(2);
    q.push(4);
    cout<<q.rfront()<<endl;
    cout<<q.empty()<<endl;
    q.pop();
    cout<<q.rfront()<<endl;
    cout<<q.empty()<<endl;

}