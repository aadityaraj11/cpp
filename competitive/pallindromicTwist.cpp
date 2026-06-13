#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool canFormPalindrome(const string &s)
{
  int left = 0, right = s.length() - 1;

  while (left < right)
  {
    char l = s[left];
    char r = s[right];

    // Check if characters match or can be made equal through one adjustment
    if (l != r)
    {
      int diff = abs(l - r);
      if (diff != 2)
      { // If difference is not 2, palindrome can't be formed
        return false;
      }
    }
    left++;
    right--;
  }
  return true;
}

int main()
{
  int T;
  cin >> T; // Number of test cases

  vector<string> results; // To store the results

  for (int i = 0; i < T; i++)
  {
    int n;
    string s;
    cin >> n >> s;

    if (canFormPalindrome(s))
    {
      results.push_back("YES");
    }
    else
    {
      results.push_back("NO");
    }
  }

  // Output all results at once
  for (const string &result : results)
  {
    cout << result << endl;
  }

  return 0;
}