#include <iostream>
#include <cstdio>
#include <deque>
#define gc getchar_unlocked
using namespace std;

void scanlong(long long &x)
{
    register long long c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

int main() {
	// your code goes here
	int n, k, nums[(int)3e6+1], l = 0, r = 0;
	bool rem[(int)3e6+1];
	deque <int> minq, maxq;
	scanint(n); scanint(k);
	long long t = 0;
	for (int x = 0; x < n; x++) {
		scanint(nums[x]);
	}
	//deque stores index of elements, not elements themselves
	minq.push_back(0);
	maxq.push_back(0);
	while (l != n) {
	  while (rem[minq.front()]) {
	    minq.pop_front();
	  }
	  while (rem[maxq.front()]) {
	    maxq.pop_front();
	  }
	  if (nums[maxq.front()] - nums[minq.front()] > k || r == n) {
	      if (r == n) {
	          break;
	      }
	    rem[l] = true;
	    l++;
	  } else {
	    t += r-l+1;
	    r++;
	    while (!minq.empty() && (nums[minq.back()] > nums[r] || rem[minq.back()])) {
	      minq.pop_back();
	    }
	    minq.push_back(r);
	    while (!maxq.empty() && (nums[maxq.back()] < nums[r] || rem[maxq.back()])) {
	      maxq.pop_back();
	    }
	    maxq.push_back(r);
	  }
	}
	cout << t << endl;
	return 0;
}
