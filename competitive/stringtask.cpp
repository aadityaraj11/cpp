#include <iostream>
#include <string>

using namespace std;

int main()
{
  string input;
  getline(cin, input);
  for (char &c : input)
  {
    c = tolower(c);
  }

  for (char &c : input)
  {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
      continue;
    }
    else
    {
      cout << '.' << c;
    }
  }

  cout << endl;
  return 0;
}