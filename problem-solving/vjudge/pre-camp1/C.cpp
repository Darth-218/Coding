#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<char> lab;
  int n, m;
  cin >> n >> m;
  char in;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> in;
      lab.push_back(in);
    }
  }
  cout << count(lab.begin(), lab.end(), 'x') << "\n";
}
