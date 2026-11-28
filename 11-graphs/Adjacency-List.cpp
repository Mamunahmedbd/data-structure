#include <iostream>
#include <vector>
using namespace std;

int main() {
  int V = 4;

  vector<vector<int>> adj(V);

  auto addEdge = [&](int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  };

  addEdge(0, 1);
  addEdge(0, 2);
  addEdge(0, 3);
  addEdge(1, 3);
  addEdge(2, 3);

  for (int i = 0; i < V; i++) {
    cout << i << ": ";

    for (int neighbor : adj[i])
      cout << neighbor << " ";

    cout << endl;
  }

  return 0;
}