#include<iostream>
using namespace std;

class Stack   {
    // properties
    public:
    int *arr;
    int top;
    int size;

    // behaviour
    Stack(int size)                             
    {
        this -> size=size;
        arr=new int (size);
        top=-1;
    }
    void push(int element)
    {
        if(size-top>1)  // checking whether empty or not 
        {
            top++;
            arr[top]=element;
        }
        else
        {
            cout<<"Stack is overflow"<<endl;
        }
    }

    void pop()    
    {
        if(top>=0)
        {
            top--;
        }
        else
        {
            cout<<"stack has already empty"<<endl;
        }
    }
    
    int peek()
    {
        if(top>=0)
        {
            return arr[top];
        }

        else
        {
            cout<<"stack is empty"<<endl;
            return -1;
        }
    }
    bool isempty()
    {
        if(top==-1)
        {
            return true;

        }
        else
        {
            return false;
        }
    }

};

int main()
{
    Stack st(5);
    st.push(3);
    st.push(4);
    st.push(6);
    st.push(8);
    cout<<"peak element is "<<st.peek()<<endl;
    st.pop();
    cout<<"peak element is "<<st.peek()<<endl;
    st.pop();
    cout<<"peak element is "<<st.peek()<<endl;
    st.pop();
    cout<<"peak element is "<<st.peek()<<endl;
    st.pop();
    cout<<st.isempty()<<endl;

}



// revision typing

// #include<iostream>
// using namespace std;

// class Stack
// {
//     // properties 
//     int *arr;
//     int top;
//     int size;

//     public:
//     Stack(int size)
//     {
//         this->size=size;
//         arr=new int(size);
//         top=-1;
//     }

//     void push(int element)
//     {
//         if(size-top>1)
//         {
//             top++;
//             arr[top]=element;
//         }
//         else
//         {
//             cout<<"full"<<endl;
//         }
//     }
     
//     void pop()
//     {
//         if(top>=0)
//         {
//             top--;
//         }
//         else
//         {
//             cout<<"empty"<<endl;
//         }
//     }

//     int peek()
//     {
//         if(top>=0)
//         {
//             return arr[top];
//         }
//         else
//         {
//             return -1;
//         }
//     }

//     bool isempty()
//     {
//         if(top==-1)
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }
// };
// int main()
// {
//     Stack st(5);
//     st.push(3);
//     st.push(4);
//     st.push(6);
//     st.push(8);
//     cout<<"peak element is "<<st.peek()<<endl;
//     st.pop();
//     cout<<"peak element is "<<st.peek()<<endl;
//     st.pop();
//     cout<<"peak element is "<<st.peek()<<endl;
//     st.pop();
//     cout<<"peakeek()<<endl;
//     cout<<st.isempt element is "<<st.py()<<endl;
// }
