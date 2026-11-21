#include <iostream>
using namespace std;

void countdown(int n) {
  if (n == 0) {
    cout << "Down!";
    return;
  }
  cout << n << " ";
  countdown(n - 1);
}

int main() {
  countdown(5);
  return 0;
}