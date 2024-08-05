#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<int> frequencySort(vector<int> &nums) {
  map<int, int> freq;
  vector<int> outvec;
  vector<int> prc;
  for (auto i : nums) {
    freq[i]++;
  }
  int min;
  for (int i = 0; i < nums.size(); i++) {
    min = nums[i];
    if (find(prc.begin(), prc.end(), nums[i]) == prc.end())
      continue;
    if (freq[i] < freq[min]) {
      min = i;
    }
  }
  for (int i = 0; i < freq[min]; i++) {
    outvec.push_back(min);
  }
  prc.push_back(min);
  return outvec;
}

int main() {
  vector<int> testvec({2, 2, 1, 1, 1, 3, 4, 4, 4, 4});
  vector<int> testoutvec = frequencySort(testvec);
  for (auto i : testoutvec) {
    cout << i << endl;
  }
}
