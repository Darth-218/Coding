#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long a[n];
    unsigned long long amax[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    amax[0] = a[0];
    for (int i = 1; i < n; i++) {
      amax[i] = a[i] + amax[i -1];
    }
    unsigned long long maxday = 0;
    for (int i = 0; i < n; i++) {
      unsigned long long asum = amax[i] + a[i];
      maxday = (asum > maxday) ? asum : maxday;
    }
    cout << maxday << "\n";
  }
}
