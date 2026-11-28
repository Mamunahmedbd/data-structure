#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool canAttendMeetings(vector<vector<int>> &intervals) {

  sort(intervals.begin(), intervals.end());

  for (int i = 1; i < intervals.size(); i++) {
    if (intervals[i][0] < intervals[i - 1][1])
      return false;
  }

  return true;
}

int main() {
  vector<vector<int>> meetings = {{0, 30}, {5, 10}, {15, 20}};

  cout << boolalpha << canAttendMeetings(meetings);

  return 0;
}