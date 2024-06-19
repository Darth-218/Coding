#include <climits>
#include <iostream>

using namespace std;

int main() {
  long long t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;
    float a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int counter = 0;
    for (int j : a) {
      if (!(j%k)) {
	cout << counter << "\n";
	continue;
      }

    }
  }
}
