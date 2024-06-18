#include <cmath>
#include <string>
#include <iostream>
#include <bitset>

int main() {

  long long t;
  std::cin >> t;
  while (t--) {
    unsigned long long x, y, l, count = 0;
    std::cin >> x >> y;
    std::string z;
    z = std::bitset<64>(x ^ y).to_string();

    for (int i = z.length(); i >= 0; i--) {
      if (z[i] == '1') break;
      else count++;
    }
    l = std::pow(2, count - 1);
    std::cout << l << "\n";
  }
}
