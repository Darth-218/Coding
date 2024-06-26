#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x, y, k;
    cin >> x >> y >> k;
    while (k--) {
      x += 1;
      while (x % y == 0) {
	x /= y;
	cout << x << "\n";
      }
    }
    cout << x << "\n";
  }
}
