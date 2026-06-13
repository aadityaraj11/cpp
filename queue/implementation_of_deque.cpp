// #include<iostream>
// using namespace std;
// class deeque{
//     public:
//     int *arr;
//     int size;   
//     int front;   
//     int rear;
//     deeque(int size)
//     {
//         arr=new int [size];
//         front=-1;
//         rear=-1;
//     }
//     void pushfront(int element)
//     {
//         if((front==0 && rear==size-1)||(rear==(front-1)%(size-1)))
//         {
//             cout<<"queue is full"<<endl;
//             return;
//         }
//         else if(front==-1)
//         {
//             front=rear=0;
//         }
//         else if(front==0)
//         {
//             front=size-1;
//         }
//         else
//         {
//             front--;
//         }
//         arr[front]=element;
//         cout<<"push kr dia"<<endl;
//         return;
//     }
//     void pushrear(int element)
//     {
//         if((front==0 && rear==size-1)||(rear==(front-1)%(size-1)))
//         {
//             cout<<"queue is full"<<endl;
//             return;
//         }
//         else if(front==-1)
//         {
//             front=rear=0;
//         }
//         else if (rear==size-1 && front!=0)
//         {
//             rear=0;
//         }
//         else
//         {
//             rear++;
//         }
//         arr[rear]=element;
//         cout<<"push kr dia"<<endl;
//         return;
//     }
//     int popfront()
//     {

//         if(front==-1)
//         {
//             cout<<"queue is empty"<<endl;
//             return 0;
//         }
//         int ans =arr[front];
//         arr[front]=-1;
//         if(front==rear)  //single element is present
//         {
//             front=rear=-1;
//         }
//         else if(front ==size-1)  //  front is at last index after pop it should go to next one
//         {
//             front =0;
//         }
//         else  // normal case pop
//         {
//             front++;
//         }
//         cout<<"pop hogya h"<<endl;;
//         return ans;
//     }
//     int poprear()
//     {
//         if(front==-1)
//         {
//             cout<<"queue is empty"<<endl;
//             return 0;
//         }
//         int ans =arr[rear];
//         arr[rear]=-1;
//         if(front==rear)  //single element is present
//         {
//             front=rear=-1;
//         }
//         else if(rear==0)  //  front is at last index after pop it should go to next one
//         {
//             rear=size-1;
//         }
//         else  // normal case pop
//         {
//             rear--;
//         }
//         cout<<"pop hogya h"<<endl;
//         return ans;
//     }
// };
// int main()
// {
//     deeque d(20);
//     d.pushrear(1);
//     d.pushfront(2);
//     d.pushrear(3);
//     d.popfront();
//     d.poprear();
//     d.poprear();
// }
#include<iostream>
using namespace std;

class deeque {
public:
    int *arr;
    int size;
    int front;
    int rear;

    deeque(int size) {
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void pushfront(int element) {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
            cout << "queue is full" << endl;
            return;
        }
        else if (front == -1) {
            front = rear = 0;
        }
        else if (front == 0) {
            front = size - 1;
        }
        else {
            front--;
        }
        arr[front] = element;
        cout << "push kr dia" <<element<< endl;
    }

    void pushrear(int element) {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
            cout << "queue is full" << endl;
            return;
        }
        else if (front == -1) {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0) {
            rear = 0;
        }
        else 
        {
            rear++;
        }
        arr[rear] = element;
        cout << "push kr dia" <<element<< endl;
    }

    int popfront() {
        if (front == -1) {
            cout << "queue is empty" << endl;
            return 0;
        }
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear) {
            front = rear = -1;
        }
        else if (front == size - 1) {
            front = 0;
        }
        else {
            front++;
        }
        cout << "popped" <<ans<< endl;
        return ans;
    }

    int poprear() {
        if (front == -1) {
            cout << "queue is empty" << endl;
            return 0;
        }
        int ans = arr[rear];
        arr[rear] = -1;
        if (front == rear) {
            front = rear = -1;
        }
        else if (rear == 0) {
            rear = size - 1;
        }
        else {
            rear--;
        }
        cout << "popped" <<ans<< endl;
        return ans;
    }
};

int main() {
    deeque d(20);
    d.pushrear(1);
    d.pushfront(2);
    d.pushrear(3);
    d.popfront();
    d.poprear();
    d.poprear();
    return 0;
}
