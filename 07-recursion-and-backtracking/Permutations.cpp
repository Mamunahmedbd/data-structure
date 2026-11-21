#include <iostream>
#include <vector>
using namespace std;

void permute(vector<int> &nums, vector<bool> &used, vector<int> &current) {

  if (current.size() == nums.size()) {
    for (int x : current)
      cout << x << " ";
    cout << endl;
    return;
  }

  for (int i = 0; i < nums.size(); i++) {
    if (used[i])
      continue;

    used[i] = true;
    current.push_back(nums[i]);

    permute(nums, used, current);

    current.pop_back();
    used[i] = false;
  }
}

int main() {
  vector<int> nums = {1, 2, 3};
  vector<bool> used(nums.size(), false);
  vector<int> current;

  permute(nums, used, current);
  return 0;
}