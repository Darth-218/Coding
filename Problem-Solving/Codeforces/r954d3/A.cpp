#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int x1, x2, x3, least, greatest;
    cin >> x1 >> x2 >> x3;
    least = min(min(x1, x2), x3);
    greatest = max(max(x1, x2), x3);
    cout << greatest - least << "\n";
  }
}
