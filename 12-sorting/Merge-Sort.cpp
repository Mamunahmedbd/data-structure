#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right) {

  vector<int> L(arr.begin() + left, arr.begin() + mid + 1);

  vector<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);

  int i = 0;
  int j = 0;
  int k = left;

  while (i < L.size() && j < R.size()) {
    if (L[i] <= R[j]) {
      arr[k++] = L[i++];
    } else {
      arr[k++] = R[j++];
    }
  }

  while (i < L.size())
    arr[k++] = L[i++];

  while (j < R.size())
    arr[k++] = R[j++];
}

void mergeSort(vector<int> &arr, int left, int right) {

  if (left >= right)
    return;

  int mid = left + (right - left) / 2;

  mergeSort(arr, left, mid);

  mergeSort(arr, mid + 1, right);

  merge(arr, left, mid, right);
}

int main() {
  vector<int> arr = {38, 12, 27, 43, 9, 31, 18, 25};

  mergeSort(arr, 0, (int)arr.size() - 1);

  for (int x : arr)
    cout << x << " ";

  return 0;
}