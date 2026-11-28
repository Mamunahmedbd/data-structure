#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> arr = {30, 10, 50, 20, 60};

  // Build max-heap: O(n)
  make_heap(arr.begin(), arr.end());

  cout << "Maximum: " << arr.front() << endl;

  // Heap sort: O(n log n)
  sort_heap(arr.begin(), arr.end());

  cout << "Sorted: ";

  for (int x : arr)
    cout << x << " ";

  return 0;
}