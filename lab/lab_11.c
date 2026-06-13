#include <stdio.h>
#include <stdlib.h>

#define MAX 50

// Function to check if the queen can be placed safely
int place(int c[], int r)
{
  for (int i = 0; i < r; i++)
  {
    if (c[i] == c[r] || abs(c[i] - c[r]) == abs(i - r))
      return 0;
  }
  return 1;
}

// Function to display the board
void display(int c[], int n)
{
  char cb[MAX][MAX]; // Increased to MAX to support larger boards

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cb[i][j] = '*';

  for (int i = 0; i < n; i++)
    cb[i][c[i]] = 'Q';

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      printf("%c", cb[i][j]);
    printf("\n");
  }
}

// Core N-Queens backtracking function
void n_queens(int n)
{
  int r = 0, found = 0;
  int c[MAX];

  c[0] = -1;

  while (r >= 0)
  {
    c[r]++;
    while (c[r] < n && !place(c, r))
      c[r]++;

    if (c[r] < n)
    {
      if (r == n - 1)
      {
        display(c, n);
        printf("\n\n");
        found = 1;
      }
      else
      {
        r++;
        c[r] = -1;
      }
    }
    else
    {
      r--;
    }
  }

  if (!found)
    printf("Placing Queens not possible for the specified n value (%d).\n", n);
}

// Main function
int main()
{
  int n;
  printf("Enter the number of queens: ");
  scanf("%d", &n);

  if (n < 1 || n > MAX)
  {
    printf("Invalid input. Please enter a value between 1 and %d.\n", MAX);
    return 1;
  }

  n_queens(n);
  return 0;
}