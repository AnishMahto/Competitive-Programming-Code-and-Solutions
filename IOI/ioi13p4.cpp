#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

void exploreCave(int n) {
  int S[n] = {0}, D[n] = {0}, alwaysZero[n] = {0}, soFar = 0;
  bool calc[5001] = {0};
  vector < pair <int, int> > known;
  //state, position
  for (int f = 0; f < n; f++) {
    int cur;
    for (int x = 0; x < n; x++) { alwaysZero[x] = 0; };
    for (int x = 0; x < known.size(); x++) {
      alwaysZero[known[x].second] = known[x].first;
    }
    //apply what we already know here
    int temp = tryCombination (alwaysZero);
    if  (temp >= soFar+1 || temp == -1) {
      cur = 0;
    } else {
      cur = 1;
    }
    //state is found, now we need to find position
    int l = 0, r = n-1;
    if (cur==1) {
      for (int x = 0; x < n; x++) { S[x] = 1; };
    } else {
      for (int x = 0; x < n; x++) { S[x] = 0; };
    }
    for (int x = 0; x < known.size(); x++) {
      S[known[x].second] = known[x].first;
    }
    bool change = cur;
    //apply what we already know here
    while (l != r) {
      //test if right is good
      for (int x = 0; x <= (l+r)/2; x++) {
        if (!calc[x]) {
          S[x] = !change;
        }
      }
      temp = tryCombination (S);
      for (int x = 0; x <= (l+r)/2; x++) {
        if (!calc[x]) {
          S[x] = !change;
        }
      }
      if (temp >= soFar+1 || temp == -1) {
        l = (l+r)/2 + 1;
      } else {
        for (int x = 0; x <= (l+r)/2; x++) {
          if (!calc[x]) {
            S[x] = change;
          }
        }
        r = (l+r)/2;
      }
    }
    known.push_back(make_pair(cur, l));
    calc[l] = true;
    S[l] = cur;
    D[l] = soFar;
    soFar++;
  } 
  answer (S, D);
}

int main () {
  
}
