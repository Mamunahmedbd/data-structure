#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr) {
  int n = arr.size();

  for (int i = 1; i < n; i++) {
    int key = arr[i];

    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = key;
  }
}

int main() {
  vector<int> arr = {7, 3, 8, 2, 6, 4, 5};

  insertionSort(arr);

  for (int x : arr)
    cout << x << " ";

  return 0;
}