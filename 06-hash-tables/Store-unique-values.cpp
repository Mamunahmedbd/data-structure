#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  unordered_set<int> s;

  s.insert(10);
  s.insert(20);
  s.insert(10); // Duplicate ignored

  cout << "Size: " << s.size() << endl;

  if (s.count(20)) {
    cout << "20 exists" << endl;
  }

  s.erase(10);

  cout << "Size after delete: " << s.size();

  return 0;
}