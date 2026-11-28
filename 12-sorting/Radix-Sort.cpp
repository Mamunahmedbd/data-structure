#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void countingSortByDigit(vector<int> &arr, long long exp) {

  int n = arr.size();

  vector<int> output(n);

  int count[10] = {};

  for (int x : arr)
    count[(x / exp) % 10]++;

  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];

  for (int i = n - 1; i >= 0; i--) {
    int digit = (arr[i] / exp) % 10;

    output[count[digit] - 1] = arr[i];

    count[digit]--;
  }

  arr = output;
}

void radixSort(vector<int> &arr) {
  if (arr.empty())
    return;

  int maxVal = *max_element(arr.begin(), arr.end());

  for (long long exp = 1; maxVal / exp > 0; exp *= 10) {

    countingSortByDigit(arr, exp);
  }
}

int main() {
  vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

  radixSort(arr);

  for (int x : arr)
    cout << x << " ";

  return 0;
}