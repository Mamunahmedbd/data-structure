#include <iostream>
using namespace std;

class Queue {
private:
  int arr[5];
  int frontIndex = 0;
  int rearIndex = -1;

public:
  void enqueue(int value) {
    if (rearIndex == 4) {
      cout << "Queue Overflow" << endl;
      return;
    }

    arr[++rearIndex] = value;
  }

  void dequeue() {
    if (frontIndex > rearIndex) {
      cout << "Queue Underflow" << endl;
      return;
    }

    frontIndex++;
  }

  void peek() {
    if (frontIndex > rearIndex) {
      cout << "Queue is empty" << endl;
      return;
    }

    cout << "Front: " << arr[frontIndex] << endl;
  }

  void display() {
    for (int i = frontIndex; i <= rearIndex; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};

int main() {
  Queue q;

  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);

  q.display();
  q.peek();

  q.dequeue();

  q.display();

  return 0;
}