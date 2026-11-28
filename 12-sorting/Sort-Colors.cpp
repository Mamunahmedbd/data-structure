#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void sortColors(vector<int> &nums) {
  int low = 0;
  int mid = 0;
  int high = (int)nums.size() - 1;

  while (mid <= high) {
    if (nums[mid] == 0) {
      swap(nums[low], nums[mid]);

      low++;
      mid++;
    } else if (nums[mid] == 1) {
      mid++;
    } else {
      swap(nums[mid], nums[high]);

      high--;
    }
  }
}

int main() {
  vector<int> nums = {2, 0, 2, 1, 1, 0};

  sortColors(nums);

  for (int x : nums)
    cout << x << " ";

  return 0;
}