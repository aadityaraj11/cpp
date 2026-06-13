#include <iostream>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++)
  {
    if (i % 2 != 0)
    {
      // Odd-numbered rows: Fill the entire row with '#'
      for (int j = 0; j < m; j++)
      {
        cout << "#";
      }
    }
    else
    {
      // Even-numbered rows: Alternate placement of '#'
      if (i % 4 == 0)
      {
        // '# at the start of the row
        cout << "#";
        for (int j = 1; j < m; j++)
        {
          cout << ".";
        }
      }
      else
      {
        // '# at the end of the row
        for (int j = 0; j < m - 1; j++)
        {
          cout << ".";
        }
        cout << "#";
      }
    }
    cout << endl; // Move to the next row
  }

  return 0;
}
