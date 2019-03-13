#include <iostream>
#include <cstdio>
#include <bitset>
#include <map>
using namespace std;

int trie[33*100001][2] = {0}, ctr = 0;
map <int, int> ind;

void add (bitset<31> tmp, int pos, int idx) {
    if (pos < 0) {
        return;
    }
    if (trie[idx][tmp.test(pos)] == 0) {
        ctr++;
        trie[idx][tmp.test(pos)] = ctr;
        add (tmp, pos-1, ctr);
    } else {
        add (tmp, pos-1, trie[idx][tmp.test(pos)]);
    }
}

bitset<31> least (bitset<31>tmp, int pos, int idx, bitset<31>ans) {
    if (pos < 0) {
        return ans;
    }
    if (trie[idx][tmp.test(pos)] != 0) {
        if (tmp.test(pos)) {
            ans.set(pos);
        }
        return least (tmp, pos-1, trie[idx][tmp.test(pos)], ans);
    } else {
        if (!tmp.test(pos)) {
            ans.set(pos);
        }
        return least (tmp, pos-1, trie[idx][!tmp.test(pos)], ans);
    }
}

int main() {
    map <int, int>::iterator it;
    bitset <31> ans, query;
    int n, q, cur, exOhAre = 0;
    scanf ("%d %d", &n, &q);
    for (int x = 0; x < n; x++) {
        scanf ("%d", &cur);
        bitset <31> tmp = cur;
        add (tmp, 30, 0);
        it = ind.find (cur);
        if (it == ind.end()) {
            ind.insert (make_pair(cur, x));
        }
        
    }
    for (int x = 0; x < q; x++) {
        scanf ("%d", &cur);
        exOhAre ^= cur;
        query = exOhAre;
        ans.reset();
        it = ind.find((int)least(query, 30, 0, ans).to_ulong());
        cout << it->second << "\n";
    }
    
    return 0;
}
