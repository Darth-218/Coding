#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int LIS(vector<int> a) {
  vector<int> l;
  for (int i = 0; i < a.size(); i++) {
    vector<int> sub;
    for (int k = 0; k < i; k++) {
      if (a[k] < a[i]) {
	sub.push_back(l[k]);
      }
    }
    sort(sub.begin(), sub.end());
    l.push_back(1 + sub[sub.size() - 1]);
  }
  sort(l.begin(), l.end());
  return l[l.size() - 1];
}

int main() {
  vector<int> test({5, 2, 8, 6, 3, 6, 9, 5});
  cout << LIS(test) << "\n";
}

