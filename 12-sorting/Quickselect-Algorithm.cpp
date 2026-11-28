#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int low, int high) {

  static mt19937 rng(random_device{}());

  uniform_int_distribution<int> dist(low, high);

  swap(arr[dist(rng)], arr[high]);

  int pivot = arr[high];
  int i = low;

  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      swap(arr[i], arr[j]);
      i++;
    }
  }

  swap(arr[i], arr[high]);

  return i;
}

int quickSelect(vector<int> &arr, int k) {
  int low = 0;
  int high = arr.size() - 1;

  while (low <= high) {
    int pi = partition(arr, low, high);

    if (pi == k)
      return arr[pi];

    if (pi < k)
      low = pi + 1;
    else
      high = pi - 1;
  }

  return -1;
}

int main() {
  vector<int> arr = {3, 2, 1, 5, 6, 4};

  int k = 2;

  int index = arr.size() - k;

  cout << quickSelect(arr, index);

  return 0;
}