#include <unordered_map>
#include <stdio.h>
#include <bitset>
#include <iostream>
using namespace std;

long long seed = 131, seedPower[5001] = {0}, h[5001] = {0}, MOD = 1e9+7;
bitset<5001> visited;
unordered_map <long long, bool> check;
string word;

long long getSubHash (int s, int e) {
    if (s==0) {
        return h[e];
    } else {
        s--;
        return (h[e] - h[s]*seedPower[e-s]%MOD + MOD)%MOD;
    }
}

int main() {
    seedPower[0] = 1;
    for (int x = 1; x <= 5000; x++) {
        seedPower[x] = seedPower[x-1]*seed%MOD;
    }
    cin >> word;
    h[0] = (int)word[0];
    for (int x = 1; x < word.length(); x++) {
        h[x] = (h[x-1]*seed + (int)word[x])%MOD;
    }
    for (int l = 1; l <= word.length()/2; l++) {
        visited.reset();
        for (int x = 0; x <= word.length()-l; x++) {
            //for all possible starting points
            if (!visited.test(x)) {
                long long initVal = getSubHash(x, x+l-1), sumHash = 0;
                for (int i = x+l; i <= word.length()-l; i+=l) {
                    if (getSubHash(i, i+l-1) == initVal) {
                        check.insert (make_pair(getSubHash(x, i+l-1), false));
                        visited.set (i);
                    } else {
                        break;
                    }
                }
            }
        }
    }
    cout << check.size() << endl;
    return 0;
}
