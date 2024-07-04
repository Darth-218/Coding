#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    string out = "";
    cin >> s;
    int record = 0;
    if (s[0] == '1') {
      record = 1;
    }
    for (int i = 1; i < n; i++) {
      if (s[i] == '1') {
	if (record > 0) {
	  out += "-";
	  record--;
	}
	else {
	  out += "+";
	  record++;
	}
      }
      else {
	out += "-";
      }
    }
    cout << out << "\n";
  }
}
