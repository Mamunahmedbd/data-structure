#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
private:
  vector<int> heap;

  void siftUp(int i) {
    while (i > 0) {
      int parent = (i - 1) / 2;

      if (heap[parent] >= heap[i])
        break;

      swap(heap[parent], heap[i]);

      i = parent;
    }
  }

  void siftDown(int i) {
    int n = heap.size();

    while (true) {
      int largest = i;
      int left = 2 * i + 1;
      int right = 2 * i + 2;

      if (left < n && heap[left] > heap[largest])
        largest = left;

      if (right < n && heap[right] > heap[largest])
        largest = right;

      if (largest == i)
        break;

      swap(heap[i], heap[largest]);

      i = largest;
    }
  }

public:
  void push(int value) {
    heap.push_back(value);

    siftUp(heap.size() - 1);
  }

  void pop() {
    if (heap.empty())
      return;

    heap[0] = heap.back();

    heap.pop_back();

    if (!heap.empty())
      siftDown(0);
  }

  void peek() {
    if (!heap.empty())
      cout << "Maximum: " << heap[0] << endl;
  }

  void display() {
    for (int x : heap)
      cout << x << " ";

    cout << endl;
  }

  void buildHeap(vector<int> arr) {
    heap = arr;

    for (int i = (int)heap.size() / 2 - 1; i >= 0; i--) {
      siftDown(i);
    }
  }
};

int main() {
  MaxHeap h;

  h.push(30);
  h.push(10);
  h.push(50);
  h.push(20);
  h.push(60);

  h.display();
  h.peek();

  h.pop();

  h.display();
  h.peek();

  return 0;
}