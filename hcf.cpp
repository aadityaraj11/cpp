#include <iostream>
using namespace std;

int main()
{
    int a , b;
    cout<<"Enter the numbers"<<endl;
    cin>>a;
    cin>>b;
    int temp;
    while (b != 0)
    {
        temp = a % b;
        if (temp == 0)
        {
            cout<<"hcf is"<<b;
            exit(0);
        }
        a = b;
        b = temp;
    }
    return 0;
}