#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<int> a(n), b(n);
  int imbalance = 0; // Keeps track of the imbalance caused by floor/ceil choices

  // First pass: Apply floor division for odd numbers and exact division for even numbers
  for (int i = 0; i < n; ++i)
  {
    cin >> a[i];

    if (a[i] % 2 == 0)
    {
      b[i] = a[i] / 2;
    }
    else
    {
      b[i] = a[i] / 2;              // floor division
      imbalance += a[i] - 2 * b[i]; // Track the difference
    }
  }

  // Second pass: Fix imbalance by changing some of the floor values to ceil
  // We only adjust floor -> ceil for odd numbers
  for (int i = 0; i < n && imbalance != 0; ++i)
  {
    if (a[i] % 2 != 0 && b[i] == a[i] / 2)
    {
      b[i] += 1; // Change from floor to ceil
      imbalance--;
    }
  }

  // Output result
  for (int i = 0; i < n; ++i)
  {
    cout << b[i] << endl;
  }

  return 0;
}
