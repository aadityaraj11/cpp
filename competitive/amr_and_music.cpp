#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;

  vector<pair<int, int>> instruments; // Pair of <days required, index>

  for (int i = 0; i < n; i++)
  {
    int days;
    cin >> days;
    instruments.push_back({days, i + 1}); // Store index starting from 1
  }

  // Sort instruments by days required in ascending order
  sort(instruments.begin(), instruments.end());

  vector<int> chosenInstruments;
  int totalDays = 0;

  for (const auto &instrument : instruments)
  {
    if (totalDays + instrument.first <= k)
    {
      totalDays += instrument.first;
      chosenInstruments.push_back(instrument.second);
    }
    else
    {
      break;
    }
  }

  // Output the result
  cout << chosenInstruments.size() << endl;
  for (int index : chosenInstruments)
  {
    cout << index << " ";
  }
  cout << endl;

  return 0;
}