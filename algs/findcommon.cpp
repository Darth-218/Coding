#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> a({5, 2, 8, 9, 4});
vector<int> b({3, 2, 9, 4});

int setfind(vector<int> a, vector<int> b) {
  unordered_set<int> s;
  int count = 0;
  for (auto i : a) s.insert(i);
  for (auto j : b) {
    if (s.find(j) == s.end()) continue;
    count++;
  }
  return count;
}

/* int sortfind(vector<int> a, vector<int> b) { */
/*   int count = 0; */
/*   sort(a.begin(), a.end()); */
/*   sort(b.begin(), b.end()); */
/*   for (int i = 0; i < a.size(); i++) { */
/*     if (a[i] == b[i]) count++; */
/*   } */
/*   return count; */
/* } */

int main() {
  cout << setfind(a, b) << " " /* << sortfind(a, b)*/ << "\n";
}
