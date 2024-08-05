#include <iostream>
#include <map>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    map<int, int> count;
    int mx = 0;
    for (int i = 0; i < n; i++) {
      count[a[i]]++;
    }
    string output = "NO";
    for (int i = n - 1; i >= 0; i--) {
      if (count[a[i]] % 2) {
        output = "YES";
        break;
      }
    }
    cout << output << "\n";
  }
}
