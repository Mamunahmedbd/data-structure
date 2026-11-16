#include <iostream>
#include <stack>
using namespace std;

int main() {
  stack<int> st;

  // Push element
  st.push(10);
  st.push(20);
  st.push(30);
  st.push(40);

  // view top
  cout << "Top: " << st.top() << endl;

  // remove top
  st.pop();

  cout << "After pop: " << st.top() << endl;

  // Display all elements
  while (!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }
  return 0;
}