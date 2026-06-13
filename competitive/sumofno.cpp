#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int n;
    cin >> n;

    int temp = n; // Preserve the value of n
    int parts = 0;
    vector<int> round_numbers;

    // Count the number of round parts and store them in order
    int place_value = 1;
    while (temp != 0)
    {
      int c = temp % 10;
      if (c != 0)
      {
        round_numbers.push_back(c * place_value); // Store the round number
        parts++;
      }
      temp = temp / 10;
      place_value *= 10;
    }

    cout << parts << endl; // Print the number of parts

    // Print the round numbers in reverse order (to match the correct output order)
    for (int i = round_numbers.size() - 1; i >= 0; i--)
    {
      cout << round_numbers[i];
      if (i != 0)
        cout << " "; // Print a space if it's not the last number
    }
    cout << endl; // Move to the next line for the next test case
  }

  return 0;
}
