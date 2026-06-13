#include <stdio.h>

int Q[10], rear = 0; // Queue for topological sort output

// Function to perform Topological Sort
void TopologicalSort(int a[10][10], int InDeg[], int n)
{
  int i, j;
  for (i = 1; i <= n; i++)
  {
    if (InDeg[i] == 0)
    {
      InDeg[i] = -1; // Mark node as visited
      Q[++rear] = i; // Add node to the topological order
      for (j = 1; j <= n; j++)
      {
        if (a[i][j] == 1 && InDeg[j] != -1)
        {
          InDeg[j]--; // Reduce the in-degree of connected nodes
        }
      }
      i = 0; // Restart the process to handle new nodes with in-degree 0
    }
  }
}

int main()
{
  int a[10][10], InDeg[10], n, i, j;

  printf("\nEnter the number of nodes in a Graph (max 10): ");
  scanf("%d", &n);

  if (n > 10 || n < 1)
  {
    printf("Please enter a valid number of nodes (1-10).\n");
    return 1;
  }

  for (i = 1; i <= n; i++)
    InDeg[i] = 0; // Initialize in-degree array

  printf("\nEnter the graph data in Adjacency Matrix representation:\n");
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
    {
      scanf("%d", &a[i][j]);
      if (a[i][j] == 1)
        InDeg[j]++; // Calculate in-degree of each node
    }

  TopologicalSort(a, InDeg, n);

  if (rear != n)
    printf("\nTopological ordering not possible (graph contains a cycle).\n");
  else
  {
    printf("\nTopological ordering is: ");
    for (i = 1; i <= rear; i++)
      printf("%d \t", Q[i]);
    printf("\n");
  }
  return 0;
}
