#include <iostream>
using namespace std;

// Function to find the minimum element index
int findMinIndex(int arr[], int n)
{
  int mini = 0;
  for (int i = 1; i < n; i++)
  {
    if (arr[i] <= arr[mini])
    {
      mini = i;
    }
  }
  return mini;
}

// Function to find the maximum element index
int findMaxIndex(int arr[], int n)
{
  int maxi = 0;
  for (int i = 1; i < n; i++)
  {
    if (arr[i] > arr[maxi])
    {
      maxi = i;
    }
  }
  return maxi;
}

int main()
{
  int n;
  cin >> n;

  int arr[100];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  int mini = findMinIndex(arr, n);
  int maxi = findMaxIndex(arr, n);

  int maxiswap = 0;

  if (mini < maxi)
  {
    maxiswap = maxi + (n - 1 - mini) - 1;
  }
  else
  {
    maxiswap = maxi + (n - 1 - mini);
  }

  cout << maxiswap << endl;

  return 0;
}