#include <iostream>
#include <map>

using namespace std;

int main() {

  long long t;
  cin >> t;

  while (t--) {
    long long input_length;
    long long maxcount = 0;
    string input;
    cin >> input_length;
    cin >> input;

    map<char, long long> charcount;
    for (int i = 0; i < input_length; i++) {
      charcount[input[i]]++;
      maxcount = (maxcount > charcount[input[i]]) ? maxcount : charcount[input[i]];
    }
    if (maxcount <= (input_length / 2))
      cout << input_length % 2 << "\n";
    else
      cout << (input_length - 2 * (input_length - maxcount)) << "\n";
  }
}
