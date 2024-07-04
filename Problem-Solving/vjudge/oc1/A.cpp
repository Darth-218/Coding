#include <iostream>
#include <string>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string time24;
    cin >> time24;
    string hourstr = "";
    string minutestr = "";
    for (int i = 0; i < 2; i++) {
      hourstr += time24[i];
    }
    for (int i = 3; i <= 4; i++) {
      minutestr += time24[i];
    }
    string time = (stoi(hourstr) >= 12) ? "PM" : "AM";
    int hours = (stoi(hourstr) < 12) ? stoi(hourstr) : stoi(hourstr) - 12;
    if (hours == 0) hours = 12;
    printf("%02d:%s %s\n", hours, minutestr.c_str(), time.c_str());
  }
}
