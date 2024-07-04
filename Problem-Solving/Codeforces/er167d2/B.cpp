#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string a, b, c = "";
    cin >> a;
    cin >> b;
    c += a;
    for (char i : b) {
      if (c.find(i) > c.length()) {
	c += i;
      }
    }
    cout << c.size() << "\n";
  }
}
