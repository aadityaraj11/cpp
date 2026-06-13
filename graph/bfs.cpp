#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

class Graph
{
public:
  unordered_map<int, list<int>> adj;

  void addEdge(int u, int v, int direction)
  {
    adj[u].push_back(v);

    if (direction == 0)
    {
      adj[v].push_back(u);
    }
  }

  void printadj()
  {
    for (auto i : adj)
    {
      cout << i.first << "->";
      for (auto j : i.second)
      {
        cout << j << ", ";
      }
      cout << endl;
    }
  }

  void bfs(unordered_map<int, bool> &visited, vector<int> &ans, int node)
  {
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty())
    {
      int frontNode = q.front();
      q.pop();
      ans.push_back(frontNode);

      for (auto i : adj[frontNode])
      {
        if (!visited[i])
        {
          q.push(i);
          visited[i] = 1;
        }
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
  g.printadj();

  cout << endl
       << endl
       << "Printing bfs:" << endl;

  vector<int> ans;
  unordered_map<int, bool> visited;
  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      g.bfs(visited, ans, i);
    }
  }

  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << ",";
  }
  return 0;
}