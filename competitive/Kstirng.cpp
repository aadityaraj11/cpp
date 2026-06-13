#include <iostream>
#include <map>
using namespace std;

int main()
{
  int k;
  string input;

  // Take input for k and the string
  cin >> k >> input;

  // Create a frequency map
  map<char, int> frequency;
  for (char c : input)
  {
    frequency[c]++;
  }

  // Check if the length of the string is divisible by k
  if (input.length() % k != 0)
  {
    cout << "-1" << endl;
    return 0;
  }

  // Check if each character's frequency is divisible by k
  for (auto &pair : frequency)
  {
    if (pair.second % k != 0)
    {
      cout << "-1" << endl;
      return 0;
    }
  }

  // If all conditions are met, print a valid k-string
  string result;
  for (auto &pair : frequency)
  {
    result += string(pair.second / k, pair.first); // Add each character "frequency/k" times
  }

  string finalResult;
  for (int i = 0; i < k; i++)
  {
    finalResult += result; // Repeat the substring k times
  }

  cout << finalResult << endl;
  return 0;
}