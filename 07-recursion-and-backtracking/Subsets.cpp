#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> &nums, int index, vector<int> &current) {

  if (index == nums.size()) {
    cout << "{ ";
    for (int x : current)
      cout << x << " ";
    cout << "}" << endl;
    return;
  }

  // Include
  current.push_back(nums[index]);
  solve(nums, index + 1, current);

  // Undo
  current.pop_back();

  // Exclude
  solve(nums, index + 1, current);
}

int main() {
  vector<int> nums = {1, 2, 3};
  vector<int> current;

  solve(nums, 0, current);
  return 0;
}