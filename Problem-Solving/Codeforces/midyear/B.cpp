#include <iostream>

using namespace std;

int main() {
  long long t;
  cin >> t;

  while (t--) {
    long long n, k;
    cin >> n >> k;
    double a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    long long factor = 1;
    for (int i = 0; i < n; i++) factor *= a[i];
    if (!(factor % k)) {
      cout << 0 << "\n";
      continue;
    }
    long long steps = 0, count = 0, maxcount = 0, maxindex;
    for (int j = 0; j < n; j++) {
	count = (long long)((a[j] / (double)k) * 100) % 100;
	if (count > maxcount) {
	  maxcount = count;
	  maxindex = j;
	}
    }
    while ((long long)a[maxindex] % k) {
      steps++;
      a[maxindex]++;
    }
    cout << steps << "\n";
  }
}
