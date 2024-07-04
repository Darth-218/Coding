#include <iostream>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  long long a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long adif[n];
  adif[0] = a[0];
  for (int i = 1; i < n; i++) {
    adif[i] = a[i - 1] - a[i];
  }
  for (int x = 0; x < m; x++) {
    long long sum;
    int s, t;
    cin >> s >> t;
    if (s < t) {
      sum = 0;
      for (;s < t; s++) {
	  sum += (adif[s] > 0) ? adif[s] : 0;
      }
      cout << sum << "\n";
    }
    else {
      sum = 0;
      for (int f = s - 1; f >= t - 1; f--) {
	sum += (adif[f] < 0) ? abs(adif[f]) : 0;
      }
      cout << sum << "\n";
    }
  }
}
