#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

class Graph
{
public:
  unordered_map<int, list<int>> adj;

  void addEdge(int u, int v, bool direction)
  {
    // direction=0 -> undirected
    // direction=1 -> directed

    // Create an edge from u to v
    adj[u].push_back(v);
    if (direction == 0)
    {
      // If undirected, create an edge from v to u
      adj[v].push_back(u);
    }
  }

  void printAdjList()
  {
    for (auto i : adj)
    {
      cout << i.first << " -> ";
      for (auto j : i.second)
      {
        cout << j << ", ";
      }
      cout << endl;
    }
  }

  void dfs(int node, unordered_map<int, bool> &visited, vector<int> &ans)
  {
    ans.push_back(node);
    visited[node] = 1;

    for (auto i : adj[node])
    {
      if (!visited[i])
      {
        dfs(i, visited, ans);
      }
    }
  }
};

int main()
{
  int n, m;

  cout << "Enter the number of nodes: ";
  cin >> n;
  cout << "Enter the number of edges: ";
  cin >> m;

  Graph g;

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    // Creating an undirected graph
    g.addEdge(u, v, 0);
  }

  // Printing the graph
  g.printAdjList();

  unordered_map<int, bool> visited;
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      g.dfs(i, visited, ans);
    }
  }

  cout << "DFS Traversal: ";
  for (int node : ans)
  {
    cout << node << ", ";
  }

  return 0;
}
