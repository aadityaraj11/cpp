#include <iostream>
using namespace std;

int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {5, 4, 3, 2, 17};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int sum[n];
    int carry = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        sum[i] = (arr1[i] + arr2[i] + carry) % 10;
        carry = (arr1[i] + arr2[i] + carry) / 10;
        // cout<<"at"<<i<<"th step"<<"sum="<<sum[i]<<"carry="<<carry<<endl;
    }

    cout << "The sum of the two arrays is: ";
    if (carry != 0)
    {
        cout << carry << ", ";
    }
    for (int i = 0; i < n; i++)
    {
        cout << sum[i];
        if (i != n - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;

    return 0;
}
