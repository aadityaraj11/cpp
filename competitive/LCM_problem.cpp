#include <iostream>
using namespace std;

int main()
{
  int t;
  cin >> t; // Number of test cases
  while (t--)
  {
    int l, r;
    cin >> l >> r; // Read range [l, r]
    if (2 * l <= r)
    {
      // Valid pair exists
      cout << l << " " << 2 * l << endl;
    }
    else
    {
      // No valid pair
      cout << "-1 -1" << endl;
    }
  }
  return 0;
}