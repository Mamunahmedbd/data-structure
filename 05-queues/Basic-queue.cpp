#include <iostream>
#include <queue>
using namespace std;

int main() {
  queue<int> q;

  q.push(10);
  q.push(20);
  q.push(30);

  cout << "Front: " << q.front() << endl;
  cout << "Rear: " << q.back() << endl;

  q.pop();

  cout << "After pop front is: " << q.front() << endl;

  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  return 0;
}

// Queue time complexity
// Operation	Simple queue	Circular queue	Priority queue
// Push	O(1)	O(1)	O(log n)
// Pop	O(1)	O(1)	O(log n)
// Front / Top	O(1)	O(1)	O(1)
// Search	O(n)	O(n)	O(n)
// Space	O(n)	O(capacity)	O(n)