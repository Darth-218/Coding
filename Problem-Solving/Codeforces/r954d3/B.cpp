#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
	cin >> a[i][j];
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
	if (i > 0 && j > 0) {
	  while (a[i][j] > a[i][j + 1] && a[i][j] > a[i][j - 1]
	    && a[i][j] > a[i + 1][j] && a[i][j] > a[i - 1][j]) {
	    a[i][j]--;
	  }
	}
	else {
	  while (a[i][j] > a[i][j + 1] && a[i][j] > a[i + 1][j] && 
	    a[i][j] > a[i - 1][j]) {
	    a[i][j]--;
	  }
	}
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
	cout << a[i][j] << " ";
      }
      cout << "\n";
    }
  }
}
