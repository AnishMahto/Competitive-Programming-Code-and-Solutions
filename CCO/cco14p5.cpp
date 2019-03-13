#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

bool comp(const pair<int, pair <int, int> > &a,
              const pair<int, pair <int, int> > &b)
{
    return (a.first > b.first);
}

int n, m, bit[2][100001] = {0} /*stores ppl in aisle C and D*/, auditorium[100001][7] = {0} /*0 means person in seat, -1 means empty seat*/, conv[1001] = {0};
long long A, B;

int query (int pos) {
  int sum = 0;
  while (pos > 0) {
    sum += bit[0][pos] + bit[1][pos];
    pos -= pos & -pos;
  }
  return sum;
}

void add (int pos, int aisle, int val) {
  while (pos <= n) {
    bit[aisle][pos] += val;
    pos += pos & -pos;
  }
}

inline long long summation (long long n) {
  n--; //dont include when the first person arrives in the room;
  return ((n+1)*n)/2;
}

int main() {
  long long pplPassed = 0, roomA = 0, roomB = 0;
  for (int x = (int)('A'); x <= (int)('F'); x++) {
    conv[x] = x-(int)('A') + 1;
  }
  string temp;
  scanf("%d%d%d%d",&n,&m,&A,&B);
  roomA = m; //initially put everyone in the bottom room;
  vector < pair <int, int> > ppl(m);
  vector < pair <int, pair <int, int> > > ppl2(m);
  for (int x = 1; x <= n; x++) {
    add (x, 0, 1);
    add (x, 1, 1);
  }
  for (int l = 0; l < m; l++) {
    int r = 0, c, passHor = 0, aisleDown, aisleUp;
    char tmp;
    scanf("%d %c",&r,&tmp);
    c = conv[(int)tmp];
    auditorium[r][c]--;
    if (c==3) {
      add (r, 0, -1);
    } else if (c==4) {
      add (r, 1, -1);
    }
    
    aisleDown = query (r);
    aisleUp = query (n) - query(r-1);
    
    if (c >= 4) {
      for (int x = 4; x < c; x++) {
        passHor += auditorium[r][x]+1;
      }
      if (auditorium[r][4] != -1) {
        //dont double count corner guy when turning on aisle
        passHor--;
      }
    } else {
      for (int x = c+1; x <= 3; x++) {
        passHor += auditorium[r][x]+1;
      }
      if (auditorium[r][3] != -1) {
        //dont double count corner guy when turning on aisle
        passHor--;
      }
    }
    ppl[l].first = aisleDown + passHor;
    ppl[l].second = aisleUp + passHor;
    pplPassed += ppl[l].first;
    ppl2[l].first = ppl[l].second-ppl[l].first;
    ppl2[l].second = ppl[l];
  }
  
  sort (ppl2.begin(), ppl2.end());
  
  for (int x = 0; x < ppl2.size(); x++) {
    //try moving person to other room;
    if (A*pplPassed + B*(summation(roomA)+summation(roomB)) >= A*(pplPassed+ppl2[x].first) + B*(summation(roomA-1) + summation(roomB+1))) {
      pplPassed += ppl2[x].first;
      roomA--;
      roomB++;
    }
  }
  
  printf ("%lld\n", A*pplPassed + B*(summation(roomA)+summation(roomB)));
  
}
