#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  unordered_map<string, int> marks;

  // Insert
  marks["Mamun"] = 95;
  marks["Samrat"] = 90;
  marks["abu"] = 85;

  // Access
  cout << "Mamun:  " << marks["Mamun"] << endl;

  // Update
  marks["Samrat"] = 88;

  // Search
  if (marks.find("Mamun") != marks.end()) {
    cout << "Mamun found" << endl;
  }

  // Delete
  marks.erase("abu");

  cout << "Total Students:  " << marks.size() << endl;

  return 0;
}