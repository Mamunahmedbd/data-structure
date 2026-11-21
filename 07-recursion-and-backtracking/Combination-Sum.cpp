#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> &nums, int target, int start, vector<int> &current) {

  if (target == 0) {
    for (int x : current)
      cout << x << " ";
    cout << endl;
    return;
  }

  for (int i = start; i < nums.size(); i++) {
    if (nums[i] > target)
      continue;

    current.push_back(nums[i]);

    solve(nums, target - nums[i], i, current);

    current.pop_back();
  }
}

int main() {
  vector<int> nums = {2, 3, 6, 7};
  vector<int> current;

  solve(nums, 7, 0, current);
  return 0;
}