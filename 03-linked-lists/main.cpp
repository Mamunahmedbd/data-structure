#include <iostream>
using namespace std;

// Node structure
struct Node {
  int data;
  Node *next;

  Node(int value) {
    data = value;
    next = nullptr;
  }
};

// Insert at beginning - O(1)
void insertBeginning(Node *&head, int value) {
  Node *newNode = new Node(value);
  newNode->next = head;
  head = newNode;
}

// Insert at end - O(n)
void insertEnd(Node *&head, int value) {
  Node *newNode = new Node(value);

  if (head == nullptr) {
    head = newNode;
    return;
  }

  Node *temp = head;

  while (temp->next != nullptr) {
    temp = temp->next;
  }

  temp->next = newNode;
}

// Delete a node by value - O(n)
void deleteNode(Node *&head, int value) {
  if (head == nullptr)
    return;

  if (head->data == value) {
    Node *temp = head;
    head = head->next;
    delete temp;
    return;
  }

  Node *temp = head;

  while (temp->next != nullptr && temp->next->data != value) {
    temp = temp->next;
  }

  if (temp->next != nullptr) {
    Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
  }
}

// Search a node - O(n)
void searchNode(Node *head, int value) {
  int position = 0;

  while (head != nullptr) {
    if (head->data == value) {
      cout << "Found at index: " << position << endl;
      return;
    }

    head = head->next;
    position++;
  }

  cout << "Not found" << endl;
}

// Reverse linked list - O(n)
Node *reverseList(Node *head) {
  Node *prev = nullptr;
  Node *curr = head;

  while (curr != nullptr) {
    Node *next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  return prev;
}

// Display linked list - O(n)
void display(Node *head) {
  while (head != nullptr) {
    cout << head->data << " -> ";
    head = head->next;
  }

  cout << "NULL" << endl;
}

// Free allocated memory
void freeList(Node *&head) {
  while (head != nullptr) {
    Node *temp = head;
    head = head->next;
    delete temp;
  }
}

int main() {
  Node *head = nullptr;

  // Insert nodes
  insertEnd(head, 10);
  insertEnd(head, 20);
  insertEnd(head, 30);
  insertEnd(head, 40);
  insertEnd(head, 50);

  cout << "Original List: ";
  display(head);

  // Insert at beginning
  insertBeginning(head, 5);

  cout << "After Insertion: ";
  display(head);

  // Search
  searchNode(head, 30);

  // Delete
  deleteNode(head, 20);

  cout << "After Deletion: ";
  display(head);

  // Reverse
  head = reverseList(head);

  cout << "Reversed List: ";
  display(head);

  // Memory cleanup
  freeList(head);

  return 0;
}

// Problem	Time	Extra space
// Reverse Linked List	O(n)	O(1)
// Merge Two Sorted Lists	O(n+m)	O(1)
// Linked List Cycle	O(n)	O(1)
// Middle of Linked List	O(n)	O(1)
// Remove Duplicates	O(n)	O(1)
// Remove Nth From End	O(n)	O(1)
// Add Two Numbers	O(max(n,m))	O(n+m)*
// Copy Random Pointer	O(n)	O(1)*
// Reorder List	O(n)	O(1)
// LRU Cache	O(1) avg.	O(capacity)
// Reverse k-Group	O(n)	O(1)
// Merge k Lists	O(N log k)	O(k)