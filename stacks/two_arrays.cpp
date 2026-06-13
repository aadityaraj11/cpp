#include<iostream>
using namespace std;

class twoStack   {
    // properties
    public:
    int *arr;
    int top1;
    int top2;
    int size;

    // behaviour
    twoStack(int size)
    {
        this -> size=size;
        arr=new int (size);
        top1=-1;
        top2=size;
    }
    void push1(int element)
    {
        if(top2-top1>1)
        {
            top1++;
            arr[top1]=element;
        }
        else
        {
            cout<<"Stack is overflow"<<endl;
        }
    }
    void push2(int element)
    {
        if(top2-top1>1)
        {
            top2--;
            arr[top2]=element;
        }
        else
        {
            cout<<"Stack is overflow"<<endl;
        }
    }

    int pop1()    
    {
        if(top1>=0)
        {
            int ans=arr[top1];
            top1--;
            return ans;
        }
        else
        {
            return -1;
        }
    }
    int pop2()    
    {
        if(top2<size)
        {
            int ans=arr[top2];
            top2++;
            return ans;
        }
        else
        {
            return -1;
        }
    }
    int peek()
    {
        if(top1>=0)
        {
            return arr[top1];
        }

        else
        {
            cout<<"stack is empty"<<endl;
            return -1;
        }
    }
    
    
    int peek2()
    {
        if(top2>=0&&top2<size)
        {
            return arr[top2];
        }

        else
        {
            cout<<"stack is empty"<<endl;
            return -1;
        }
    }
    bool isempty()
    {
        if(top1==-1 && top2==size)
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
    twoStack st(10);
    st.push1(3);
    st.push1(4);
    st.push2(6);
    st.push2(8);
    cout<<"peak element is "<<st.peek()<<endl;
    st.pop1();
    cout<<"peak element is "<<st.peek()<<endl;
    st.pop1();
    cout<<"peak element is "<<st.peek()<<endl;
    cout<<"peak element of 2nd array is "<<st.peek2()<<endl;
    st.pop2();
    cout<<"peak element is "<<st.peek2()<<endl;
    st.pop2();
    cout<<"peak element is "<<st.peek2()<<endl;
    cout<<st.isempty()<<endl;

}