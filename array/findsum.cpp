#include <iostream>
using namespace std;
int main()
{
    int arr1[5] = {1, 2, 3, 4, 5};
    int sum = 12;
    int i = 0;
    int j = 0;
    for (i = 0; i < 5; i++)
    {
        for (j = i + 1; j < 5; j++)
        {
            for (int k = j + 1; k < 5; k++)
            {
                int res = arr1[i] + arr1[j] + arr1[k];
                if (res == sum)
                {
                    cout << arr1[i] << "," << arr1[j] << "," << arr1[k];
                    cout << endl;
                    exit(0);
                }
            }
        }
    }
}




