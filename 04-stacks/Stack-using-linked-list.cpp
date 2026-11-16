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

class Stack {
private:
  Node *topNode = nullptr;

public:
  void push(int value) {
    Node *newNode = new Node(value);
    newNode->next = topNode;
    topNode = newNode;
  }

  void pop() {
    if (topNode == nullptr)
      return;

    Node *temp = topNode;
    topNode = topNode->next;
    delete temp;
  }

  void peek() {
    if (topNode != nullptr)
      cout << topNode->data << endl;
  }

  void display() {
    Node *temp = topNode;

    while (temp != nullptr) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }

  ~Stack() {
    while (topNode != nullptr)
      pop();
  }
};

int main() {
  Stack st;

  st.push(10);
  st.push(20);
  st.push(30);

  st.display();
  st.pop();
  st.peek();

  return 0;
}