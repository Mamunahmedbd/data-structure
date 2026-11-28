#include <iostream>
#include <vector>
using namespace std;

int main() {
  int V = 4;

  vector<vector<int>> graph(V, vector<int>(V, 0));

  graph[0][1] = graph[1][0] = 1;
  graph[0][2] = graph[2][0] = 1;
  graph[0][3] = graph[3][0] = 1;
  graph[1][3] = graph[3][1] = 1;
  graph[2][3] = graph[3][2] = 1;

  for (auto &row : graph) {
    for (int x : row)
      cout << x << " ";

    cout << endl;
  }

  return 0;
}