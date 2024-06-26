#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int x1, y1, x2, y2;
  cin >> x1;
  cin >> y1;
  cin >> x2;
  cin >> y2;
  cout.precision(17);
  cout << sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) << "\n";
}
