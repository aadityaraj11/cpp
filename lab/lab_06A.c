#include <stdio.h>

#define INF 999
#define MAX 10

int min(int a, int b)
{
  return (a < b) ? a : b;
}

void floyd(int p[MAX][MAX], int n)
{
  int i, j, k;
  for (k = 0; k < n; k++)
  {
    for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
      {
        p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
      }
    }
  }
}

int main()
{
  int a[MAX][MAX], n, i, j;

  printf("Enter the number of vertices (n <= %d): ", MAX);
  scanf("%d", &n);

  printf("Enter the graph data (use %d for INF where no edge exists):\n", INF);
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      scanf("%d", &a[i][j]);
    }
  }

  floyd(a, n);

  printf("\nShortest path matrix:\n");
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      if (a[i][j] == INF)
      {
        printf("INF ");
      }
      else
      {
        printf("%d ", a[i][j]);
      }
    }
    printf("\n");
  }

  return 0;
}