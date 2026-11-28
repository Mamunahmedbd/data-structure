#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<double> &arr) {
  for (int i = 1; i < arr.size(); i++) {
    double key = arr[i];

    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = key;
  }
}

void bucketSort(vector<double> &arr) {
  int n = arr.size();

  if (n == 0)
    return;

  vector<vector<double>> buckets(n);

  // Distribute values into buckets
  for (double x : arr) {
    int index = n * x;

    buckets[index].push_back(x);
  }

  // Sort each bucket
  for (auto &bucket : buckets)
    insertionSort(bucket);

  // Combine all buckets
  int index = 0;

  for (auto &bucket : buckets) {
    for (double x : bucket)
      arr[index++] = x;
  }
}

int main() {
  vector<double> arr = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12};

  bucketSort(arr);

  for (double x : arr)
    cout << x << " ";

  return 0;
}