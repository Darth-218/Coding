#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    double n;
    cin >> n;
    if (n >= 2) {
      cout << ceil(n / 4) << "\n";
    } else
      cout << 0 << "\n";
  }
}
