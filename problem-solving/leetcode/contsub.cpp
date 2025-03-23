#include <vector>
#include <iostream>

using namespace std;
bool checkSubarraySum(vector<int> &nums, int k);

int main() {
  vector<int> test({0, 0});
  cout << checkSubarraySum(test, 1) << endl;
}

bool checkSubarraySum(vector<int> &nums, int k) {
  int sum;
  if (nums.size() < 2) return false;
  for (int start = 0; start <= nums.size() - 2; start++){
    sum = nums[start];
    for (int index = start + 1; index <= nums.size() - 1; index++) {
      sum += nums[index];
      if (sum % k == 0) return true;
    }
  }
  return false;
}
