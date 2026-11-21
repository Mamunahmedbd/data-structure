#include <iostream>
#include <unordered_map>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
  unordered_map<char, int> freq;

  for (char c : magazine)
    freq[c]++;

  for (char c : ransomNote) {
    if (freq[c] == 0)
      return false;

    freq[c]--;
  }

  return true;
}

int main() {
  cout << boolalpha;
  cout << canConstruct("aa", "aab");

  return 0;
}