#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x1, y1, x2, y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    if (abs(x2 - y2) == abs(x1 - y1)) {
      cout << "YES" << "\n";
    }
    else {
      cout << "NO" << "\n";
    }
  }
}
