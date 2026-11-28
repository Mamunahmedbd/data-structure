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

Node *mergeLists(Node *left, Node *right) {
  Node dummy(0);

  Node *tail = &dummy;

  while (left && right) {
    if (left->data <= right->data) {
      tail->next = left;
      left = left->next;
    } else {
      tail->next = right;
      right = right->next;
    }

    tail = tail->next;
  }

  tail->next = left ? left : right;

  return dummy.next;
}

Node *sortList(Node *head) {
  if (!head || !head->next)
    return head;

  Node *slow = head;
  Node *fast = head->next;

  // Find the middle
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  Node *right = slow->next;

  // Split into two linked lists
  slow->next = nullptr;

  Node *left = sortList(head);

  right = sortList(right);

  return mergeLists(left, right);
}

int main() {
  Node *head = new Node(4);

  head->next = new Node(2);
  head->next->next = new Node(1);
  head->next->next->next = new Node(3);

  head = sortList(head);

  Node *temp = head;

  while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }

  // Free memory
  while (head) {
    Node *next = head->next;

    delete head;

    head = next;
  }

  return 0;
}