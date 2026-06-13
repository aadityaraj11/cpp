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
        front=0;
        rear=0;
    }
    void push (int element)
    {
        if(rear==size)
        {
            cout<<"queue is full";
        }
        else
        {
            arr[rear]=element;
            rear++;
        }
    }
    int pop()
    {
        if(front==rear)
        {
            cout<<"queue is empty";
            return 0;
        }
        else
        {
            int ans =arr[front];
            arr[front]=-1;
            front++;
            if(front==rear)
            {
                front=rear=0;
                return ans;
            }
        }
    }
    int rfront()
    {
        if(front==rear)
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
        if(front==rear)
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
    q.push(1);
    q.push(2);
    q.push(4);
    cout<<q.rfront()<<endl;
    cout<<q.empty()<<endl;
    q.pop();
    q.pop();
    q.pop();
    cout<<q.rfront()<<endl;
    cout<<q.empty()<<endl;

}