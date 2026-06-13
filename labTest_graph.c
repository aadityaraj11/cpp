#include <stdio.h>
#include <stdlib.h>

#define MAX_CITIES 20

// Structure to represent a graph
struct Graph
{
  int vertices; // N
  int adjMatrix[MAX_CITIES][MAX_CITIES];
};

// Function to create a graph of cities
struct Graph createGraph(int N)
{
  struct Graph graph;
  graph.vertices = N;

  // Initialize the adjacency matrix with all zeros
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      graph.adjMatrix[i][j] = 0;
    }
  }

  // Populate the adjacency matrix with connections between cities
  printf("Enter connections between cities (0 for no connection, 1 for connection):\n");
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (i != j)
      {
        printf("Is there a connection between city %d and city %d? (1/0): ", i + 1, j + 1);
        scanf("%d", &graph.adjMatrix[i][j]);
      }
    }
  }

  return graph;
}

// Function to perform Depth-First Search (DFS) from a starting node
void DFS(struct Graph graph, int start, int visited[])
{
  visited[start] = 1;
  printf("City %d is reachable.\n", start + 1);

  for (int i = 0; i < graph.vertices; i++)
  {
    if (graph.adjMatrix[start][i] == 1 && !visited[i])
    {
      DFS(graph, i, visited);
    }
  }
}

// Function to print all nodes reachable from a given starting node using DFS
void printDFS(struct Graph graph, int start)
{
  int visited[MAX_CITIES] = {0};
  printf("Nodes reachable from City %d using DFS:\n", start + 1);
  DFS(graph, start, visited);
}

// Function to perform Breadth-First Search (BFS) from a starting node
void BFS(struct Graph graph, int start, int visited[])
{
  int queue[MAX_CITIES];
  int front = 0, rear = -1;

  visited[start] = 1;
  queue[++rear] = start;

  while (front <= rear)
  {
    int current = queue[front++];
    printf("City %d is reachable.\n", current + 1);

    for (int i = 0; i < graph.vertices; i++)
    {
      if (graph.adjMatrix[current][i] == 1 && !visited[i])
      {
        visited[i] = 1;
        queue[++rear] = i;
      }
    }
  }
}

// Function to print all nodes reachable from a given starting node using BFS
void printBFS(struct Graph graph, int start)
{
  int visited[MAX_CITIES] = {0};
  printf("Nodes reachable from City %d using BFS:\n", start + 1);
  BFS(graph, start, visited);
}

int main()
{
  int N, startCity;

  // Ask for the number of cities
  printf("Enter the number of cities: ");
  scanf("%d", &N);

  // Create the graph based on user input
  struct Graph cityGraph = createGraph(N);

  // Ask for the starting city
  printf("Enter the starting city to explore: ");
  scanf("%d", &startCity);

  // Validate the input city number
  if (startCity > 0 && startCity <= N)
  {
    // Print reachable nodes using DFS
    printDFS(cityGraph, startCity - 1);

    // Print reachable nodes using BFS
    printBFS(cityGraph, startCity - 1);
  }
  else
  {
    printf("Invalid starting city. Please enter a valid city number.\n");
  }

  return 0;
}
