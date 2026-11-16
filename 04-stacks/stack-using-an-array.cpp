#include <iostream>
using namespace std;

class Stack {
private:
  int arr[5];
  int topIndex = -1;

public:
  void push(int value) {
    if (topIndex == 4) {
      cout << "Stack Overflow" << endl;
      return;
    }

    arr[++topIndex] = value;
  }

  void pop() {
    if (topIndex == -1) {
      cout << "Stack Underflow" << endl;
      return;
    }

    topIndex--;
  }

  void peek() {
    if (topIndex == -1) {
      cout << "Stack is empty" << endl;
      return;
    }

    cout << "Top: " << arr[topIndex] << endl;
  }

  void display() {
    for (int i = topIndex; i >= 0; i--) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};

int main() {
  Stack st;

  st.push(10);
  st.push(20);
  st.push(30);

  st.display();

  st.peek();

  st.pop();

  st.display();

  return 0;
}