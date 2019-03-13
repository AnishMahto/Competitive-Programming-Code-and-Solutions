#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    scanf ("%d", &n);
    long long sum = 0, exOhAre = 0, cur;
    for (int x = 0; x < n; x++) {
        scanf ("%lld", &cur);
        sum += cur;
        exOhAre ^= cur;
    }
    cout << sum - exOhAre << endl;
}
