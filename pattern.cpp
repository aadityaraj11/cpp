#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter no of rows\n";
    cin >> n;
    int g=n;
    for (int i = 1; i < n; i++)
    {
        
        for (int j=1; j <= g-1; j++)
        {
                cout<<" ";
        
        }
        for (int k = 1; k <= i; k++)
        {
            cout << k << " ";
        }
        cout << endl;
        g--;
    }
    return 0;
}