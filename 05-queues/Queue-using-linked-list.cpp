#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;

  Node(int value) {
    data = value;
    next = nullptr;
  }
};

class Queue {
private:
  Node *frontNode = nullptr;
  Node *rearNode = nullptr;

public:
  void enqueue(int value) {
    Node *newNode = new Node(value);

    if (rearNode == nullptr) {
      frontNode = rearNode = newNode;
      return;
    }

    rearNode->next = newNode;
    rearNode = newNode;
  }

  void dequeue() {
    if (frontNode == nullptr) {
      cout << "Queue is empty" << endl;
      return;
    }

    Node *temp = frontNode;
    frontNode = frontNode->next;

    if (frontNode == nullptr)
      rearNode = nullptr;

    delete temp;
  }

  void peek() {
    if (frontNode != nullptr)
      cout << "Front: " << frontNode->data << endl;
  }

  void display() {
    Node *temp = frontNode;

    while (temp != nullptr) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }

  ~Queue() {
    while (frontNode != nullptr)
      dequeue();
  }
};

int main() {
  Queue q;

  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);

  q.display();
  q.dequeue();
  q.peek();

  return 0;
}