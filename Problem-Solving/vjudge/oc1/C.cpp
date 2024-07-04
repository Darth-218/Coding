#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long sum = 1;
    while (n != 1) {
      sum += n;
      n = floor(n/2);
    }
    cout << sum << "\n";
  }
}
