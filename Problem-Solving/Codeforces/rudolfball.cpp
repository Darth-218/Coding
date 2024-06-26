#include <iostream>
#include <set>
#include <vector>
using namespace std;

set<int> throws(int num_players, int num_throws, int thrower, vector<pair<int, char>> throws_order) {
  set<int> players;
  set<int> subprob;
  int new_thrower;
  for (int i = 0; i < num_throws; i++) {
    if (throws_order[i].second == '0') {
      new_thrower = (thrower + throws_order[i].first > num_players) ? throws_order[i].first - (thrower - num_players) : thrower + throws_order[i].first;
      subprob = throws(num_players, num_throws - 1, new_thrower, throws_order);
    }
    if (throws_order[i].second == '1') {
      new_thrower = (thrower - throws_order[i].first < 0) ? throws_order[i].first - (thrower - num_players) : thrower + throws_order[i].first;
      subprob = throws(num_players, num_throws - 1, new_thrower, throws_order);
    }
    if (throws_order[i].second == '?') {
      new_thrower = (thrower - throws_order[i].first < 0) ? throws_order[i].first - (thrower - num_players) : thrower + throws_order[i].first;
      new_thrower = (thrower + throws_order[i].first > num_players) ? throws_order[i].first - (thrower - num_players) : thrower + throws_order[i].first;
      subprob = throws(num_players, num_throws - 1, new_thrower, throws_order);
    }
    players.merge(subprob);
  }
  return players;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, x;
    vector<pair<int, char>> moves;
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
      pair<int, char> initmoves;
      cin >> initmoves.first >> initmoves.second;
      moves.push_back(initmoves);
    }
    set<int> finalplayers = throws(n, m, x, moves);
    int playerscount = finalplayers.size();
    cout << playerscount;
    for (auto i : finalplayers) {
      cout << i << " ";
    }
  }
}
