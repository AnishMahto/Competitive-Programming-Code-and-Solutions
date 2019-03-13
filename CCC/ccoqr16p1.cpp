#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#define gc getchar_unlocked
using namespace std;

bool comp (pair < pair <long long, long long>, int> &i, pair < pair <long long, long long>, int> &j) {
    if (i.first.first == j.first.first) {
        return i.first.second < j.first.second;
    }
    return i.first.first < j.first.first;
}

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
	int n;
	long long a, b;
    scanint(n);
    vector < pair < pair <long long, long long> , int> > sortedX, sortedY;
    long long invertedPos[n] = {0}, sameYleft[n] = {0}, sameYright[n] = {0}, sameXabove[n] = {0}, sameXbelow[n] = {0};
    for (int x = 0; x < n; x++) {
        scanlong(a); scanlong(b);
        sortedX.push_back(make_pair(make_pair(a, b), x));
        sortedY.push_back(make_pair(make_pair(b, a), x));
    }
    sort (sortedX.begin(), sortedX.end(), comp);
    sort (sortedY.begin(), sortedY.end(), comp);
    for (int x = 0; x < sortedY.size(); x++) {
        invertedPos[sortedY[x].second] = x;
        if (x > 0) {
            if (sortedY[x - 1].first.first == sortedY[x].first.first) {
                sameYleft[x] = sameYleft[x - 1] + 1;
            }
            if (sortedX[x - 1].first.first == sortedX[x].first.first) {
                sameXbelow[x] = sameXbelow[x - 1] + 1;
            }
        }
    }
    for (int x = n - 1; x >= 0; x--) {
        if (x < n - 1) {
            if (sortedY[x + 1].first.first == sortedY[x].first.first) {
                sameYright[x] = sameYright[x + 1] + 1;
            }
            if (sortedX[x + 1].first.first == sortedX[x].first.first) {
                sameXabove[x] = sameXabove[x + 1] + 1;
            }
        }
    }
    long long total = 0;
    for (int x = 0; x < sortedX.size(); x++) {
        total += 2 * sameXabove[x] * sameXbelow[x] * sameYleft[invertedPos[sortedX[x].second]] * sameYright[invertedPos[sortedX[x].second]];
    }
    cout << total << endl;
	return 0;
}
