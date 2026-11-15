#include <iostream>
#include <string>
using namespace std;

int main() {
  string str = "Mamun Ahmed";
  char target = 'h';

  for (int i = 0; i < str.length(); i++) {
    if (str[i] == target) {
      cout << "Found at index: " << i << endl;
      return 0;
    }
  }
  cout << "Not found";
  return 0;
}

// String time complexity
// Operation	Time complexity
// Access str[i]	O(1)
// Update str[i]	O(1)
// Length str.length()	O(1)
// Search for a character	O(n)
// Insert at beginning	O(n + m)
// Delete at beginning	O(n)
// Reverse string	O(n)
// Compare two strings	O(n) worst case