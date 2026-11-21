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

Node *insert(Node *root, int value) {
  if (root == nullptr)
    return new Node(value);

  if (value < root->data)
    root->left = insert(root->left, value);

  else if (value > root->data)
    root->right = insert(root->right, value);

  return root;
}

bool search(Node *root, int value) {
  if (root == nullptr)
    return false;

  if (root->data == value)
    return true;

  if (value < root->data)
    return search(root->left, value);

  return search(root->right, value);
}

Node *deleteNode(Node *root, int value) {
  if (root == nullptr)
    return nullptr;

  if (value < root->data) {
    root->left = deleteNode(root->left, value);
  } else if (value > root->data) {
    root->right = deleteNode(root->right, value);
  } else {
    if (root->left == nullptr) {
      Node *temp = root->right;
      delete root;
      return temp;
    }

    if (root->right == nullptr) {
      Node *temp = root->left;
      delete root;
      return temp;
    }

    Node *successor = root->right;

    while (successor->left != nullptr)
      successor = successor->left;

    root->data = successor->data;
    root->right = deleteNode(root->right, successor->data);
  }

  return root;
}

int main() {
  Node *root = nullptr;

  root = insert(root, 50);
  root = insert(root, 30);
  root = insert(root, 70);
  root = insert(root, 20);
  root = insert(root, 40);

  cout << boolalpha << search(root, 40) << endl;

  root = deleteNode(root, 30);

  inorder(root);
  freeTree(root);

  return 0;
}