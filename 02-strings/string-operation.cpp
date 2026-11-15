#include <iostream>
#include <string>
using namespace std;

int main() {
  string str = "Hello";

  // Access
  cout << str[0] << endl;

  // Insert
  str.insert(5, " World");
  cout << str << endl;

  // Update
  str[0] = 'Y';
  cout << str << endl;

  // Delete
  str.erase(0, 1);
  cout << str << endl;

  // Search
  cout << str.find("World") << endl;

  // Length
  cout << str.length() << endl;

  return 0;
}