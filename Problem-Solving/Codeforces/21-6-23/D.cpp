#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, q, l, r;
    cin >> n;
    long long a[n];
    for (long long m = 0; m < n; m++) cin >> a[m];
    cin >> q;
    while (q--) {
      cin >> l >> r;
      int h = 0;
      unordered_map<long long, long long> map;
      for (int x = l; x < r; x++) {
	map[a[x]]++;
      }
      for (int x = l; x < r; x++) {
	if (map[a[x]] == (r - l)) {
	  cout << -1 << " " << -1 << "\n";
	  break;
	}
	else {

	}
      }
    }
  }
}
