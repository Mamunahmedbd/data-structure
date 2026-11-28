#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void countingSort(vector<int> &arr) {
  if (arr.empty())
    return;

  int minVal = *min_element(arr.begin(), arr.end());

  int maxVal = *max_element(arr.begin(), arr.end());

  int range = maxVal - minVal + 1;

  vector<int> count(range, 0);
  vector<int> output(arr.size());

  // Count occurrences
  for (int x : arr)
    count[x - minVal]++;

  // Calculate cumulative counts
  for (int i = 1; i < range; i++)
    count[i] += count[i - 1];

  // Traverse backward to preserve stability
  for (int i = (int)arr.size() - 1; i >= 0; i--) {
    int index = arr[i] - minVal;

    output[count[index] - 1] = arr[i];

    count[index]--;
  }

  arr = output;
}

int main() {
  vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

  countingSort(arr);

  for (int x : arr)
    cout << x << " ";

  return 0;
}