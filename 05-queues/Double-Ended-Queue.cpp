#include <deque>
#include <iostream>

using namespace std;

int main() {
  deque<int> dq;

  dq.push_back(10);
  dq.push_back(20);
  dq.push_front(5);

  dq.pop_back();

  for (int x : dq)
    cout << x << " ";

  return 0;
}