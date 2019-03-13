#include <iostream>
#include <string.h>
using namespace std;

int trie[1000005][30], count = 0, words[1000005];

void insert (string word) {
    int pos = 0;
    words[0]=1000001;
    for (int x = 0; x < word.length(); x++) {
        int idx = (int)word[x] - 97;
        if (trie[pos][idx] != 0) {
            pos = trie[pos][idx];
        } else {
            count++;
            trie[pos][idx] = count;
            pos = count;
        }
        words[pos]++;
    }
}

int query (string word) {
    int pos = 0, cnt = 0;
    for (int x = 0; x < word.length(); x++) {
        int idx = (int)word[x] - 97;
        if (words[pos]==1) {
            return cnt;
        } else {
            cnt++;
            pos = trie[pos][idx];
        }
    }
    return (int)word.length();
}

int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    string cur;
    cin >> t;
    for (int o = 1; o <= t; o++) {
        int ans = 0;
        count = 0;
        memset (trie, 0, sizeof(trie));
        memset (words, 0, sizeof(words));
        cin >> n;
        for (int x = 0; x < n; x++) {
            cin >> cur;
            insert (cur);
            ans += query (cur);
        }
        cout << "Case #" << o << ": " << ans << "\n";
    }
}
