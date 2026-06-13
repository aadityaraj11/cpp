#include <stdio.h>
#define INF 999

int prim(int c[10][10], int n, int s)
{
  int v[10], i, j, sum = 0, ver[10], d[10], min, u;

  for (i = 1; i <= n; i++)
  {
    ver[i] = s;
    d[i] = c[s][i];
    v[i] = 0;
  }

  v[s] = 1; // mark source vertex as visited

  for (i = 1; i < n; i++)
  { // run n-1 times
    min = INF;

    for (j = 1; j <= n; j++)
    {
      if (v[j] == 0 && d[j] < min)
      {
        min = d[j];
        u = j;
      }
    }

    v[u] = 1;
    sum = sum + d[u];
    printf("\n%d -> %d \t(current cost: %d)", ver[u], u, sum);

    for (j = 1; j <= n; j++)
    {
      if (v[j] == 0 && c[u][j] < d[j])
      {
        d[j] = c[u][j];
        ver[j] = u;
      }
    }
  }

  return sum;
}

int main()
{
  int c[10][10], i, j, res, s, n;

  printf("Enter number of nodes in the graph: ");
  scanf("%d", &n);

  printf("Enter the cost adjacency matrix (use %d for no edge):\n", INF);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      scanf("%d", &c[i][j]);

  printf("Enter the source vertex: ");
  scanf("%d", &s);

  res = prim(c, n, s);

  printf("\n\nTotal cost of the Minimum Spanning Tree = %d\n", res);

  return 0;
}
