#include <stdio.h>
#define MAX 10

void warsh(int p[MAX][MAX], int n)
{
  int i, j, k;
  for (k = 0; k < n; k++)
  {
    for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
      {
        p[i][j] = p[i][j] || (p[i][k] && p[k][j]);
      }
    }
  }
}

int main()
{
  int a[MAX][MAX], n, i, j;

  printf("Enter the number of vertices (n <= %d): ", MAX);
  scanf("%d", &n);

  printf("Enter the graph data (adjacency matrix, use 1 for edge and 0 for no edge):\n");
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      scanf("%d", &a[i][j]);
    }
  }

  warsh(a, n);

  printf("\nTransitive Closure of the given graph is:\n");
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }

  return 0;
}