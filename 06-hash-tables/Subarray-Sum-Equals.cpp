#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int subarraySum(vector<int> &nums, int k) {
  unordered_map<long long, int> freq;

  freq[0] = 1;

  long long sum = 0;
  int count = 0;

  for (int x : nums) {
    sum += x;

    if (freq.count(sum - k))
      count += freq[sum - k];

    freq[sum]++;
  }

  return count;
}

int main() {
  vector<int> nums = {1, 1, 1};

  cout << subarraySum(nums, 2) << endl;

  return 0;
}