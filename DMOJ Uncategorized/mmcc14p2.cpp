#include <iostream>
using namespace std;

string rows[2001];
long long h[2001][5001] = {0}, seed = 131, seedPower[5001] = {0}, dp[2001][2001] = {0}, MOD = 1e9+7;
int n, m, order[2001];

long long seg[4*2001] = {0}, segId[4*2001];

long long getSubstringHash (int s, int e, int id) {
    s--;
    if (s < 0) {
        return h[id][e];
    } else {
        return (h[id][e] - h[id][s]*seedPower[e-s]);
    }
}

int binarySearch (int id1, int id2, int len) {
    if (rows[id1][0] != rows[id2][0]) {
        return 0;
    }
    int lo = 1, hi = len;
    if (hi < lo) {
        return 0;
    }
    while (lo < hi) {
        int mid = (lo+hi)/2;
        if (getSubstringHash(0, mid, id1)==getSubstringHash(0, mid, id2)) {
            lo = mid+1;
        } else {
            hi = mid;
        }
    }
    return lo;
}

void build (int pos, int l, int r) {
    if (l==r) {
        seg[pos] = m;
        segId[pos] = l;
    } else if (l > r) {
        return;
    } else {
        int mid = (l+r)/2;
        build (2*pos, l, mid);
        build (2*pos+1, mid+1, r);
        segId[pos] = segId[2*pos];
        seg[pos] = binarySearch(segId[2*pos], segId[2*pos+1], min(seg[2*pos], seg[2*pos+1]));
    }
}

pair <int, int> query (int pos, int l, int r, int tl, int tr) {
    if (l >= tl && r <= tr) {
        return make_pair (seg[pos], segId[pos]);
    } else if (l > tr || r < tl || l > r) {
        return make_pair(-1,-1);
    } else {
        int mid = (l+r)/2;
        pair <int, int> le = query (2*pos, l, mid, tl, tr), ri = query (2*pos+1, mid+1, r, tl, tr);
        if (ri.first==-1) {
            return le;
        } else if (le.first==-1) {
            return ri;
        } else {
            return make_pair(binarySearch(le.second, ri.second, min(le.first, ri.first)), le.second);
        }
    }
}

void update (int pos, int l, int r, int tl, int tr, int newId) {
    if (l==tl && r==tr) {
        seg[pos] = m;
        segId[pos] = newId;
    } else if (l > tr || r < tl || l > r) {
        return;
    } else {
        int mid = (l+r)/2;
        update (2*pos, l, mid, tl, tr, newId);
        update (2*pos+1, mid+1, r, tl, tr, newId);
        segId[pos] = segId[2*pos];
        seg[pos] = binarySearch(segId[2*pos], segId[2*pos+1], min(seg[2*pos], seg[2*pos+1]));
    }
    return;
}

int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    seedPower[0] = 1;
    for (int x = 1; x < 5001; x++) {
        seedPower[x] = seedPower[x-1]*seed;
    }
    cin >> n >> m;
    for (int x = 0; x < n; x++) {
        order[x] = x;
        cin >> rows[x];
        h[x][0] = (int)rows[x][0];
        for (int i = 1; i < rows[x].length(); i++) {
            h[x][i] = (h[x][i-1]*seed + (int)rows[x][i]);
        }
    }
    build (1, 0, n-1);
    int q, i, j;
    cin >> q;
    for (int a = 0; a < q; a++) {
        cin >> i >> j;
        i--;
        j--;
        cout << query (1, 0, n-1, i, j).first*(j-i+1) << "\n";
        update (1, 0, n-1, i, i, order[j]);
        update (1, 0, n-1, j, j, order[i]);
        int tmp = order[j];
        order[j] = order[i];
        order[i] = tmp;
    }
}
