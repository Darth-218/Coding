#include <iostream>
#include <vector>
using namespace std;

int LIS(vector<int> a) {
  vector<int> subs;
  int sub = 0, count = 0;
  for (int i = 0; i < a.size(); i++, sub = 0) {
    for (int k = 0; k < a.size(); k++) {
      if (a[k] > a[i] && k > i) {
	sub++;
      }
    }
    subs.push_back(sub);
  }
  sort(subs.begin(), subs.end());
  return subs[subs.size() - 1] + 1;
}

int main() {
  vector<int> test({5, 2, 8, 6, 3, 6, 9, 5});
  cout << LIS(test) << "\n";
}

