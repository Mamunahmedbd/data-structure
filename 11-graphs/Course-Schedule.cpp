#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool canFinish(int n, vector<vector<int>> &prerequisites) {
  vector<vector<int>> adj(n);
  vector<int> indegree(n, 0);

  for (auto &p : prerequisites) {
    adj[p[1]].push_back(p[0]);
    indegree[p[0]]++;
  }

  queue<int> q;

  for (int i = 0; i < n; i++) {
    if (indegree[i] == 0)
      q.push(i);
  }

  int completed = 0;

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    completed++;

    for (int next : adj[node]) {
      if (--indegree[next] == 0)
        q.push(next);
    }
  }

  return completed == n;
}

int main() {
  vector<vector<int>> prerequisites = {{1, 0}, {2, 1}};

  cout << boolalpha << canFinish(3, prerequisites);

  return 0;
}