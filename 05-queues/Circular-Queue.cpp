#include <iostream>
using namespace std;

class CircularQueue {
  int arr[5];
  int front = 0;
  int rear = 0;
  int count = 0;

public:
  void enqueue(int value) {
    if (count == 5) {
      cout << "Queue Full" << endl;
      return;
    }

    arr[rear] = value;
    rear = (rear + 1) % 5;
    count++;
  }

  void dequeue() {
    if (count == 0) {
      cout << "Queue Empty" << endl;
      return;
    }

    front = (front + 1) % 5;
    count--;
  }

  void display() {
    for (int i = 0; i < count; i++) {
      cout << arr[(front + i) % 5] << " ";
    }
    cout << endl;
  }
};

int main() {
  CircularQueue q;

  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  q.enqueue(40);
  q.enqueue(50);

  q.dequeue();
  q.dequeue();

  q.enqueue(60);
  q.enqueue(70);

  q.display();

  return 0;
}