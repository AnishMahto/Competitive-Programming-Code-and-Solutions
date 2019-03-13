#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
#include <algorithm>
#define gc getchar_unlocked
using namespace std;

vector < vector <int> > nums(2001);
bool check[2001] = {0};

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
	vector <int> temp;
	int n, k, q, current, pSum[100001] = {0}, a, b, s, e;
    scanint(n); scanint(k); scanint(q);
    for (int x = 1; x <= n; x++) {
        scanint(current);
        nums[current + 1000].push_back(x); 
        if (x == 0) {
            pSum[x] = current;
        } else {
            pSum[x] = current + pSum[x - 1];
        }
    }
    for (int x = 0; x < 2001; x++) {
        sort (nums[x].begin(), nums[x].end());
    }
    vector <int>::iterator it2;
    for (int x = 0; x < q; x++) {
        scanint(a);scanint(b);scanint(s);scanint(e);
        if (pSum[e] - pSum[s - 1] > k) {
            if (nums[a + 1000].size() == 0 || nums[b + 1000].size() == 0) {
                printf("No\n");
            } else {
                int pos;
                it2 = lower_bound(nums[a + 1000].begin(), nums[a + 1000].end(), s);
                pos = it2 - nums[a + 1000].begin();
                if (nums[a + 1000][pos] <= e && nums[a + 1000][pos] >= s) {
                    it2 = lower_bound(nums[b + 1000].begin(), nums[b + 1000].end(), s);
                    pos = it2 - nums[b + 1000].begin();
                    if (nums[b + 1000][pos] <= e && nums[b + 1000][pos] >= s) {
                        printf("Yes\n");
                    } else {
                        printf("No\n");
                    }
                } else {
                    printf("No\n");
                }
            }
        } else {
            printf("No\n");
        }
    }
	return 0;
}
