#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#define scan(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;
using namespace std;

void scanint(long long &x)
{
    register long long c = getchar_unlocked();
    x = 0;
    long long neg = 0;
    for(;((c<48 || c>57) && c != '-');c = getchar_unlocked());
    if(c=='-') {neg=1;c=getchar_unlocked();}
    for(;c>47 && c<58;c = getchar_unlocked()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

long long belongsTo[150001], inBlock[150001], delta[150001] = {0}, rootN, n, m, q, blockSum[388], rightMost[388][150001] = {0}, posInLine[150001], sizeOfLine[150001] = {0}, numberOfBlocks;
vector < vector <long long> > prevBlock(150001);
vector < vector <long long> > lines(150001);

long long actualVal (int l, int pos) {
  return lines[l][(pos - delta[l] + sizeOfLine[l]) % sizeOfLine[l]];
}

void update (int line) {
  blockSum[prevBlock[line][0]] += actualVal (line, posInLine[rightMost[prevBlock[line][prevBlock[line].size()-1]][line]]);
  blockSum[prevBlock[line][0]] -= actualVal (line, posInLine[rightMost[prevBlock[line][0]][line]]);
  for (int x = 1; x < prevBlock[line].size(); x++) {
    blockSum[prevBlock[line][x]] += actualVal(line, posInLine[rightMost[prevBlock[line][x-1]][line]]);
    blockSum[prevBlock[line][x]] -= actualVal(line, posInLine[rightMost[prevBlock[line][x]][line]]);
  }
  delta[line]++;
  delta[line] %= sizeOfLine[line];
}

long long query (int l, int r) {
  long long total = 0;
  //get sum of all complete blocks inbetween block l and r exclusive
  int startBlock = inBlock[l], endBlock = inBlock[r];
  for (int x = startBlock+1; x < endBlock; x++) {
    total += blockSum[x];
  }
  //get leftmost block thru iteration O(sqrt(n))
  for (int x = l; (x <= n && inBlock[x] == inBlock[l] && x <= r); x++) {
    total += actualVal(belongsTo[x], posInLine[x]);
  }
  //get rightmost block thru iteration O(sqrt)
  if (inBlock[l] == inBlock[r]) {
    return total;
  }
  for (int x = r; (x >= 1 && inBlock[x] == inBlock[r]); x--) {
    total += actualVal(belongsTo[x], posInLine[x]);
  }
  return total;
}

int main () {
  long long cur, l, r, cmd;
  scanint (n); scanint (m); scanint (q);
  rootN = /*floor*/(sqrt ((double)n));
  for (int x = 1; x <= n; x++) {
    scanint (belongsTo[x]);
    inBlock[x] = ((double)x/(double)rootN);
    numberOfBlocks = inBlock[x]+1;
    posInLine[x] = sizeOfLine[belongsTo[x]];
    sizeOfLine[belongsTo[x]]++;
  }
  for (int x = 1; x <= n; x++) {
    scanint (cur);
    lines[belongsTo[x]].push_back(cur);
    blockSum[inBlock[x]] += cur;
    rightMost[inBlock[x]][belongsTo[x]] = x;
    if (prevBlock[belongsTo[x]].size() == 0 || prevBlock[belongsTo[x]].back() != inBlock[x]) {
      prevBlock[belongsTo[x]].push_back(inBlock[x]);
    }
  }
  for (int x = 1; x <= q; x++) {
    scanint (cmd);
    if (cmd == 1) {
      scanint (l); scanint (r);
      printf ("%lld\n", query(l, r));
    } else {
      scanint (cur);
      update (cur);
    }
  }
}
