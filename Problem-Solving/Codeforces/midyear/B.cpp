#include <iostream>
#include <map>

using namespace std;

int main() {
  long long t;
  cin >> t;

  while (t--) {
    long long n, k, closest, count;
    cin >> n >> k;
    long long a[n];

    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    
    for (int j = 0; j < n; j++) {
      count = (long long)(((double)a[j] / k) * 100) % 100;
      cout << "count: " << count << "\n";
      if (count == 0) {
	break;
      }
      closest = (count > closest) ? count : closest;
    }
    while (closest % k) {
      closest++;
    }
    cout << closest << "\n";
  }
}
