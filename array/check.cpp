#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> nums{1, 2, 3, 4, 5};

    int count = 0;
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] > nums[0])
        {
            count++;
        }
    }
    if (nums[n - 1] > nums[0])
    {
        count++;
    }
    cout << count;

    return 0;
}