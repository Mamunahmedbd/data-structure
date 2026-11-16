#include <iostream>
using namespace std;

int main() {
  int arr[10] = {10, 20, 30, 40, 50};
  int n = 5;

  // Insertion at index 2
  for (int i = n; i > 2; i--) {
    arr[i] = arr[i - 1];
  }
  arr[2] = 25;
  n++;

  // update index
  arr[0] = 15;

  // search for 40 which is called Linear Search
  for (int i = 0; i < n; i++) {
    if (arr[i] == 40) {
      cout << "Found at : Index " << i << endl;
      break;
    }
  }

  // delete element at index 3
  for (int i = 3; i < n - 1; i++) {
    arr[i] = arr[i + 1];
  }
  n--;

  // display array
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}

// Operation	Time complexity
// Access by index	O(1)
// Search (unsorted)	O(n)
// Update by index	O(1)
// Insert at beginning	O(n)
// Insert at end (free capacity)	O(1)
// Delete at beginning	O(n)
// Delete at end	O(1)