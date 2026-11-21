#include <iostream>
#include <queue>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int value) {
    data = value;
    left = right = nullptr;
  }
};

// Root -> Left -> Right
void preorder(Node *root) {
  if (root == nullptr)
    return;

  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

// Left -> Root -> Right
void inorder(Node *root) {
  if (root == nullptr)
    return;

  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

// Left -> Right -> Root
void postorder(Node *root) {
  if (root == nullptr)
    return;

  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
}

// BFS traversal
void levelOrder(Node *root) {
  if (root == nullptr)
    return;

  queue<Node *> q;
  q.push(root);

  while (!q.empty()) {
    Node *current = q.front();
    q.pop();

    cout << current->data << " ";

    if (current->left)
      q.push(current->left);

    if (current->right)
      q.push(current->right);
  }
}

void freeTree(Node *root) {
  if (!root)
    return;
  freeTree(root->left);
  freeTree(root->right);
  delete root;
}

int main() {
  Node *root = new Node(50);

  root->left = new Node(30);
  root->right = new Node(70);

  root->left->left = new Node(20);
  root->left->right = new Node(40);

  root->right->left = new Node(60);
  root->right->right = new Node(80);

  cout << "Preorder: ";
  preorder(root);

  cout << "\nInorder: ";
  inorder(root);

  cout << "\nPostorder: ";
  postorder(root);

  cout << "\nLevel Order: ";
  levelOrder(root);

  freeTree(root);
  return 0;
}