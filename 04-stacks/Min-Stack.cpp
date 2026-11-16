#include <iostream>
#include <stack>
using namespace std;

class MinStack {
  stack<int> st;
  stack<int> minSt;

public:
  void push(int val) {
    st.push(val);

    if (minSt.empty() || val <= minSt.top())
      minSt.push(val);
  }

  void pop() {
    if (st.top() == minSt.top())
      minSt.pop();

    st.pop();
  }

  int top() { return st.top(); }

  int getMin() { return minSt.top(); }
};

int main() {
  MinStack st;

  st.push(5);
  st.push(3);
  st.push(7);

  cout << "Minimum: " << st.getMin() << endl;

  st.pop();
  st.pop();

  cout << "Minimum: " << st.getMin() << endl;

  return 0;
}