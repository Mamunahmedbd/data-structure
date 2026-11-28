#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
  int val;
  vector<Node *> neighbors;

  Node(int value) : val(value) {}
};

Node *cloneGraph(Node *node, unordered_map<Node *, Node *> &copies) {

  if (!node)
    return nullptr;

  if (copies.count(node))
    return copies[node];

  Node *copy = new Node(node->val);

  copies[node] = copy;

  for (Node *neighbor : node->neighbors) {
    copy->neighbors.push_back(cloneGraph(neighbor, copies));
  }

  return copy;
}

int main() {
  Node *a = new Node(1);
  Node *b = new Node(2);
  Node *c = new Node(3);

  a->neighbors = {b, c};
  b->neighbors = {a, c};
  c->neighbors = {a, b};

  unordered_map<Node *, Node *> copies;

  Node *cloned = cloneGraph(a, copies);

  cout << "Cloned node: " << cloned->val << endl;

  cout << "Neighbors: ";

  for (Node *neighbor : cloned->neighbors)
    cout << neighbor->val << " ";

  for (auto &p : copies)
    delete p.second;

  delete a;
  delete b;
  delete c;

  return 0;
}