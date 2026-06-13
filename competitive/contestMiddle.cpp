#include <iostream>
#include <iomanip> // for setfill and setw
using namespace std;

int main()
{
  int h1, m1, h2, m2;

  // Step 1: Read time in hh:mm format
  char colon;
  cin >> h1 >> colon >> m1; // reads hh:mm
  cin >> h2 >> colon >> m2;

  // Step 2: Convert time to minutes
  int start = h1 * 60 + m1;
  int end = h2 * 60 + m2;

  // Step 3: Calculate midpoint
  int mid = (start + end) / 2;

  // Step 4: Convert back to hh:mm
  int h3 = mid / 60;
  int m3 = mid % 60;

  // Step 5: Print with leading zeros
  cout << setfill('0') << setw(2) << h3 << ":"
       << setfill('0') << setw(2) << m3 << endl;

  return 0;
}
