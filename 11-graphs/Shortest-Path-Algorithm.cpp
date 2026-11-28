#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<long long> dijkstra(vector<vector<pair<int, int>>> &adj, int source) {

  int n = adj.size();

  vector<long long> dist(n, LLONG_MAX);

  // distance, vertex
  using P = pair<long long, int>;

  priority_queue<P, vector<P>, greater<P>> pq;

  dist[source] = 0;
  pq.push({0, source});

  while (!pq.empty()) {
    auto [distance, node] = pq.top();
    pq.pop();

    // Ignore outdated heap entries
    if (distance != dist[node])
      continue;

    for (auto [neighbor, weight] : adj[node]) {
      long long newDist = distance + weight;

      if (newDist < dist[neighbor]) {
        dist[neighbor] = newDist;

        pq.push({newDist, neighbor});
      }
    }
  }

  return dist;
}

int main() {
  int V = 5;

  vector<vector<pair<int, int>>> adj(V);

  auto addEdge = [&](int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  };

  addEdge(0, 1, 4);
  addEdge(0, 2, 1);
  addEdge(2, 1, 2);
  addEdge(1, 3, 1);
  addEdge(2, 3, 5);
  addEdge(3, 4, 3);

  auto dist = dijkstra(adj, 0);

  for (int i = 0; i < V; i++) {
    cout << "0 -> " << i << ": ";

    if (dist[i] == LLONG_MAX)
      cout << "Unreachable";
    else
      cout << dist[i];

    cout << endl;
  }

  return 0;
}