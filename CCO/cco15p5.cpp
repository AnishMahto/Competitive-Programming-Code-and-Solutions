#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>
using namespace std;

int n, d;
double dp[101][12][12][12][12] = {0}, ans = 0;
vector < pair <int, int> > notes;

double inline tunedNotes (vector <int> D, vector <int> drums) {
  double count = 0;
  for (int x = 0; x < d; x++) {
    if (D[x] != drums[x]) {
      count++;
    }
  }
  return count;
}

bool inline check (vector <int> drums, int nxt) {
  for (int x = 0; x < d; x++) {
    if (drums[x]==notes[nxt].second) {
      return true;
    }
  }
  return false;
}

double solve (int before, vector <int> D) {
  if (dp[before][D[0]][D[1]][D[2]][D[3]] > 0) {
    return dp[before][D[0]][D[1]][D[2]][D[3]];
  } else if (before==notes.size()) {
    return 2000000000;
  } else {
    dp[before][D[0]][D[1]][D[2]][D[3]] = -1;
    for (int x = 0; x < d; x++) {
      if (D[x]==notes[before].second) {
        dp[before][D[0]][D[1]][D[2]][D[3]] = max (dp[before][D[0]][D[1]][D[2]][D[3]], solve (before+1, D));
        break;
      }
    }
    vector <int> drums(4);
    for (int x = 0; x <= 11; x++) {
      drums[0] = drums[1] = drums[2] = drums[3] = 0;
      drums[0] = x;
      if (d > 1) {
        for (int i = x+1; i <= 11; i++) {
          drums[1] = i;
          if (d > 2) {
            for (int z = i+1; z <= 11; z++) {
              drums[2] = z;
              if (d > 3) {
                for (int y = z+1; y <= 11; y++) {
                  drums[3] = y;
                  if (!check(drums, before)) {
                    continue;
                  }
                  dp[before][D[0]][D[1]][D[2]][D[3]] = max (dp[before][D[0]][D[1]][D[2]][D[3]], min (solve (before+1, drums), (double)(notes[before].first-notes[before-1].first)/tunedNotes (D, drums)));
                }
              } else {
                if (!check(drums, before)) {
                    continue;
                  }
                dp[before][D[0]][D[1]][D[2]][D[3]] = max (dp[before][D[0]][D[1]][D[2]][D[3]], min (solve (before+1, drums), (double)(notes[before].first-notes[before-1].first)/tunedNotes (D, drums)));
              }
            }
          } else {
            if (!check(drums, before)) {
              continue;
            }
          dp[before][D[0]][D[1]][D[2]][D[3]] = max (dp[before][D[0]][D[1]][D[2]][D[3]], min (solve (before+1, drums), (double)(notes[before].first-notes[before-1].first)/tunedNotes (D, drums)));
          }
        }
      } else {
        if (!check(drums, before)) {
          continue;
        }
        dp[before][D[0]][D[1]][D[2]][D[3]] = max (dp[before][D[0]][D[1]][D[2]][D[3]], min (solve (before+1, drums), (double)(notes[before].first-notes[before-1].first)/tunedNotes (D, drums)));
      }
    }
    return dp[before][D[0]][D[1]][D[2]][D[3]];
  }
}

int main() {
  int a, b;
  scanf ("%d %d", &n, &d);
  vector <int> drums;
  for (int x = 0; x < n; x++) {
    drums.push_back(0);
  }
  notes.push_back(make_pair(0,0));
  for (int x = 0; x < n; x++) {
    scanf ("%d %d", &a, &b);
    notes.push_back(make_pair(a, b-1));
  }
  for (int x = 0; x <= 11; x++) {
    drums[0] = drums[1] = drums[2] = drums[3] = 0;
    drums[0] = x;
    if (d > 1) {
      for (int i = x+1; i <= 11; i++) {
        drums[1] = i;
        if (d > 2) {
          for (int z = i+1; z <= 11; z++) {
            drums[2] = z;
            if (d > 3) {
              for (int y = z+1; y <= 11; y++) {
                drums[3] = y;
                if (!check(drums, 1)) {
                  continue;
                }
                ans = max (ans, solve (1, drums));
              }
            } else {
              if (!check(drums, 1)) {
                continue;
              }
              ans = max (ans, solve (1, drums));
            }
          }
        } else {
          if (!check(drums, 1)) {
            continue;
          }
          ans = max (ans, solve (1, drums));
        }
      }
    } else {
      if (!check(drums, 1)) {
        continue;
      }
      ans = max (ans, solve (1, drums));
    }
  }
  if (ans == 2000000000) {
    ans = 0;
  }
  cout << fixed << setprecision(2) << ans << endl;
}
