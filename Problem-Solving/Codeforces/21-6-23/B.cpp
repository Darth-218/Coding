#include <iostream>
#include <string>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string x, y;
    cin >> x;
    cin >> y;
    string outx, outy;
    int z = 0;
    for (int i = 0; i < x.size(); i++) {
      if (z == 0) {
	if (x[i] > y[i]) {
	  z = 1;
	  outx += x[i], outy += y[i];
	}
	else if (x[i] < y[i]) {
	  z = 1;
	  outy += x[i], outx += y[i];
	}
	else {
	  outx += x[i], outy += y[i];
	}
      }
      else {
	if (x[i] > y[i]) {
	  outy += x[i], outx += y[i];
	}
	else {
	  outx += x[i], outy += y[i];
	}
      }
    }
    cout << outx << "\n" << outy << "\n";
  }
}
