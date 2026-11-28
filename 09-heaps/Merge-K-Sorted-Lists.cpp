#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int data;
  Node *next;

  Node(int value) {
    data = value;
    next = nullptr;
  }
};

struct Compare {
  bool operator()(Node *a, Node *b) { return a->data > b->data; }
};

Node *mergeKLists(vector<Node *> &lists) {
  priority_queue<Node *, vector<Node *>, Compare> pq;

  for (Node *head : lists) {
    if (head != nullptr)
      pq.push(head);
  }

  Node dummy(0);
  Node *tail = &dummy;

  while (!pq.empty()) {
    Node *node = pq.top();
    pq.pop();

    if (node->next != nullptr)
      pq.push(node->next);

    tail->next = node;
    tail = node;
  }

  return dummy.next;
}

int main() {
  Node *a = new Node(1);
  a->next = new Node(4);
  a->next->next = new Node(5);

  Node *b = new Node(1);
  b->next = new Node(3);
  b->next->next = new Node(4);

  Node *c = new Node(2);
  c->next = new Node(6);

  vector<Node *> lists = {a, b, c};

  Node *result = mergeKLists(lists);

  while (result != nullptr) {
    cout << result->data << " ";

    Node *temp = result;
    result = result->next;
    delete temp;
  }

  return 0;
}