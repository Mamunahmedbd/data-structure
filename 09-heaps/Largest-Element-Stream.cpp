#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class KthLargest {
  int k;

  priority_queue<int, vector<int>, greater<int>> pq;

public:
  KthLargest(int k, vector<int> &nums) {
    this->k = k;

    for (int x : nums)
      add(x);
  }

  int add(int val) {
    pq.push(val);

    if (pq.size() > k)
      pq.pop();

    return pq.top();
  }
};

int main() {
  vector<int> nums = {4, 5, 8, 2};

  KthLargest kth(3, nums);

  cout << kth.add(3) << endl;
  cout << kth.add(5) << endl;
  cout << kth.add(10) << endl;
  cout << kth.add(9) << endl;
  cout << kth.add(4) << endl;

  return 0;
}