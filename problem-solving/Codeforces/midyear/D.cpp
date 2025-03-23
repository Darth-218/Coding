#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long t;
  cin >> t;
  while (t--) {
    bool output = true;
    long long n;
    cin >> n;
    vector<long long> a;
    vector<long long> b;
    long long x;
    for (int i = 0; i < n; i++) {
      cin >> x;
      a.push_back(x);
      b.push_back(x);
    }
    sort(b.begin(), b.end());
    for (int j = 0; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
	if (a[j] > a[k] && (a[j] % 2) == (a[k] % 2)) {
	  a[k] = a[k] + a[j];
	  a[j] = a[k] - a[j];
	  a[k] = a[k] - a[j];
	}
      }
    }
    for (int m = 0; m < n; m++) {
      if (a[m] == b[m]) continue;
      output = false;
      break;
    }
    printf((output == 1) ? "YES\n" : "NO\n");
  }
}
