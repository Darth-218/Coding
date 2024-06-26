#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    string s, c;
    cin >> n >> m;
    cin >> s;
    int ind[m];
    for (int i = 0; i < m; i++) cin >> ind[i];
    cin >> c;
    for (int i = 0; i < m; i++) {
      s[ind[i]] = c[i];
    }
    cout << s << "\n";
  }
}
