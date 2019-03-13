#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector < pair <string, int> > cards;
bool dp[11][11][11] = {0};

int solve (int pos, int t, vector <int> chosen) {
  if (chosen.size() == 3) {
      if (!dp[chosen[0]][chosen[1]][chosen[2]])
      for (int x = 0; x < chosen.size(); x++) {
        cout << cards[chosen[x]].first << " ";
      } cout << endl;
      dp[chosen[0]][chosen[1]][chosen[2]] = true;
  } else if (pos >= cards.size()) {
    return 0;
  } else {
    for (int x = pos; x < cards.size(); x++) {
      if (t - cards[x].second >= 0) {
      chosen.push_back(x);
      solve (x+1, t - cards[x].second, chosen);
      chosen.pop_back();
      }
    }
  }
}

int main () {
  int t, n, c;
  string name;
  cin >> n >> t;
  for (int x = 0; x < n; x++) {
    cin >> name >> c;
    cards.push_back(make_pair(name, c));
  }
  sort (cards.begin(), cards.end());
  vector <int> temp;
  solve (0, t, temp);
}
