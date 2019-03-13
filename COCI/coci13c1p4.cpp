#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <map>
#define gc getchar_unlocked
using namespace std;

void scanint(long long &x) {
	register long long c = gc();
	x = 0;
	long long neg = 0;
	for (; ((c<48 || c>57) && c != '-'); c = gc());
	if (c == '-') { neg = 1; c = gc(); }
	for (; c>47 && c<58; c = gc()) { x = (x << 1) + (x << 3) + c - 48; }
	if (neg) x = -x;
}

multimap <long long, bool> bags;
vector < pair <long long, long long> > loot;

int main() {
	// your code goes here
	long long n, k, m, v, c;
	long long totalVal = 0;
	scanint(n);scanint(k);
	for (int x = 0; x < n; x++) {
	    scanint(m);scanint(v);
	    loot.push_back(make_pair(v, m));
	}
	for (int x = 0; x < k; x++) {
	    scanint(c);
	    bags.insert(make_pair(c, false));
	}
	sort (loot.begin(), loot.end());
	long long counterLoot = n - 1;
	multimap <long long, bool>::iterator it;
	while (!bags.empty() && counterLoot >= 0) {
	  it = bags.lower_bound(loot[counterLoot].second);
	  if (it != bags.end()) {
	    bags.erase(it);
	    totalVal += loot[counterLoot].first;
	  }
	  counterLoot--;
	}
	cout << totalVal << endl;
	return 0;
}
