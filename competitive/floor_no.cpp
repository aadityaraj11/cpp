#include <iostream>
using namespace std;

int main()
{
  int t;
  cin >> t;

  int n, x;
  while (t--) // Process each test case
  {
    cin >> n >> x;

    if (n == 1 || n == 2)
    {
      cout << "1" << endl; // First floor only
    }
    else
    {
      int count = (n - 2 + x - 1) / x; // Calculate the remaining floors
      cout << count + 1 << endl;       // Include the first floor
    }
  }
  return 0;
}