#include <iostream>

using namespace std;

int main() {
  long long t; cin >> t;
  while (t--) {
    long long n; cin >> n;
    long long a[n];
    a[0] = 6, a[1] = 8;
    for (long long i = 2; i < n; i++) {
      a[i] = a[i - 2] + a[i - 1];
      while ((3 * a[i]) % (a[i - 2] + a[i - 1]) == 0)
	a[i]++;
    }
    for (long long j = 0; j < n; j++) cout << a[j] << " ";
    cout << "\n";
  }
}
