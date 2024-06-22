#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, count = 0;
    cin >> a >> b >> c;
    if (a == b) {
      cout << count << "\n";
      continue;
    }
    int greater = (a > b) ? a : b;
    int lesser = (a <= b) ? a : b;
    while (greater > lesser) {
      greater -= c, lesser += c, count++;
    }
    cout << count << "\n";
  }
}
