#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void BFS(vector<vector<int>> &adj, int start) {
  vector<bool> visited(adj.size(), false);

  queue<int> q;

  visited[start] = true;
  q.push(start);

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    cout << node << " ";

    for (int neighbor : adj[node]) {
      if (!visited[neighbor]) {
        visited[neighbor] = true;
        q.push(neighbor);
      }
    }
  }
}

void DFS(vector<vector<int>> &adj, int node, vector<bool> &visited) {

  visited[node] = true;

  cout << node << " ";

  for (int neighbor : adj[node]) {
    if (!visited[neighbor])
      DFS(adj, neighbor, visited);
  }
}

int main() {
  vector<vector<int>> adj = {{1, 2}, {0, 3, 4}, {0, 5}, {1}, {1}, {2}};

  cout << "BFS: ";
  BFS(adj, 0);

  vector<bool> visited(adj.size(), false);

  cout << "\nDFS: ";
  DFS(adj, 0, visited);

  return 0;
}