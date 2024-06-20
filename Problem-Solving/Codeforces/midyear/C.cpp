#include <iostream>

using namespace std;

int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int a[n];
    a[0] = 6, a[1] = 8;
    for (int i = 2; i < n; i++) a[i] = a[i - 2] + a[i - 1] + 1;
    for (int j = 0; j < n; j++) cout << a[j] << " ";
    cout << "\n";
  }
}
