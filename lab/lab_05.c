#include <stdio.h>
int max(int a, int b)
{
  return (a > b) ? a : b;
}

int knapsack(int n, int W, int wt[], int val[])
{
  int i, j; // Corrected `w` to `j` for consistency
  int K[n + 1][W + 1];

  // Build table K[][] in bottom-up manner
  for (i = 0; i <= n; i++)
  {
    for (j = 0; j <= W; j++)
    {
      if (i == 0 || j == 0)
      {
        K[i][j] = 0; // Fixed missing semicolon
      }
      else if (wt[i - 1] <= j)
      { // Corrected comment alignment
        K[i][j] = max(val[i - 1] + K[i - 1][j - wt[i - 1]], K[i - 1][j]);
      }
      else
      {
        K[i][j] = K[i - 1][j];
      }
    }
  }
  return K[n][W]; // Return the maximum profit
}

int main()
{
  int n, W, i;
  printf("\nEnter the number of objects: ");
  scanf("%d", &n);

  int wt[n], val[n]; // Dynamic array based on n

  printf("\nEnter the knapsack capacity: ");
  scanf("%d", &W);

  printf("\nEnter profit followed by weight:\n");
  for (i = 0; i < n; i++)
  {
    scanf("%d %d", &val[i], &wt[i]);
  }

  printf("\nMax profit = %d\n", knapsack(n, W, wt, val));
  return 0;
}