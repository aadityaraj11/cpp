#include <iostream>
using namespace std;
int main()
{
    int a[20], temp, i, j;
    cout << "Enter elements to be sorted:" << endl;
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < 4; i++)
    {
        int minindex = i;
        for (j = i + 1; j < 5; j++)
        {
            if (a[j] < a[minindex])
            {
                minindex = j;
            }
        }
        temp = a[i];
        a[i] = a[minindex];
        a[minindex] = temp;
        cout<<"swapping"<<a[i]<<"and"<<a[minindex]<<endl;
    }
    cout << "sorted element is:" << endl;
    for (i = 0; i < 5; i++)
    {
        cout << a[i] << "\t";
    }

    return 0;
}