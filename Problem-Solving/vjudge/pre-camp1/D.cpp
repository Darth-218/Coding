#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  int S;
  cin >> S;
  string state;
  int limit;
  unordered_map<string, int> limits;
  for (int i = 0; i < S; i++) {
    cin >> state >> limit;
    limits[state] = limit;
  }
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> state;
    cout << limits[state] << "\n";
  }
}
