#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  vector<string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};

  unordered_map<string, vector<string>> groups;

  for (string word : words) {
    string key = word;
    sort(key.begin(), key.end());

    groups[key].push_back(word);
  }

  for (const auto &group : groups) {
    for (const string &word : group.second)
      cout << word << " ";

    cout << endl;
  }

  return 0;
}