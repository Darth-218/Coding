#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    pair<int, int> coin_pos;
    cin >> coin_pos.first >> coin_pos.second;
    coin_pos.second -= abs(coin_pos.first);
    cout << abs(coin_pos.second) << " " << abs(coin_pos.first) << "\n";
    if (abs(coin_pos.second) > abs(coin_pos.first)) {
      cout << "NO\n";
    }
    else {
      cout << "YES\n";
    }
  }
}
