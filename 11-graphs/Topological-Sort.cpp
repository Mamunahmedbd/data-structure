#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> topologicalSort(vector<vector<int>> &adj) {
  int n = adj.size();

  vector<int> indegree(n, 0);
  vector<int> result;

  for (int u = 0; u < n; u++) {
    for (int v : adj[u])
      indegree[v]++;
  }

  queue<int> q;

  for (int i = 0; i < n; i++) {
    if (indegree[i] == 0)
      q.push(i);
  }

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    result.push_back(node);

    for (int neighbor : adj[node]) {
      indegree[neighbor]--;

      if (indegree[neighbor] == 0)
        q.push(neighbor);
    }
  }

  if (result.size() != n)
    return {}; // Cycle detected

  return result;
}

int main() {
  vector<vector<int>> adj = {{1, 2}, {3}, {3}, {}};

  for (int x : topologicalSort(adj))
    cout << x << " ";

  return 0;
}