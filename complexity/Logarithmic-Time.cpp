#include <iostream>
using namespace std;

int main() {
  int arr[] = {10, 20, 30, 40, 50, 60, 70};
  int n = 7;
  int target = 60;

  int left = 0, right = n - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
      cout << "Found at index" << mid;
      return 0;
    }

    if (arr[mid] < target)
      left = mid + 1;
    else
      right = mid - 1;
  }

  cout << "Not Found";
  return 0;
}