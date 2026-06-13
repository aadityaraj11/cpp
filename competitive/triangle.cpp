#include <iostream>
using namespace std;

int main()
{
  int t; // Number of test cases
  cin >> t;
  while (t--)
  {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // Select x, y, z based on the given conditions
    int x = b; // x is in range [a, b]
    int y = c; // y is in range [b, c]
    int z = c; // z is in range [c, d]

    // Output the chosen x, y, z
    cout << x << " " << y << " " << z << endl;
  }
  return 0;
}