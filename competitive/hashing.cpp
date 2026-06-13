#include <iostream>
#include <vector>
using namespace std;

bool isAnagram(string s, string p)
{

  vector<int> ans;
  vector<int> hash(26, 0);
  vector<int> phash(26, 0);

  int window = p.size();

  int len = s.size();

  int left = 0;
  int right = 0;

  while (right < window)
  {
    // STORING HASH OF FIRST X SIZE OF WINDOW
    phash[p[right] - 'a'] += 1;
    hash[s[right++] - 'a'] += 1;
  }

  right -= 1; // putting right back into range of window

  while (right < len)
  {
    if (phash == hash)
    {
      return true;
    }
    right += 1;

    if (right != len)
    {
      hash[s[right] - 'a'] += 1;
    }
    hash[s[left] - 'a'] -= 1;

    left += 1;
  }
  return false;
}

int main()
{
  int n;
  cin >> n;
  string s;
  string p;

  while (n--)
  {
    cin >> p;
    cin >> s;

    if (s.length() < p.length())
    {
      cout << "NO\n";
      continue;
    }

    if (isAnagram(s, p))
    {
      cout << "YES\n";
    }
    else
    {
      cout << "NO\n";
    }
  }

  return 0;
}