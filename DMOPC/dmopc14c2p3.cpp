#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int n;
    cin >> n;
    
    vector <long> e;
    vector <long> l;
    
    long current;
    
    for (int x = 0; x < n; x++) {
        cin >> current;
        e.push_back(current);
    }
    
    for (int x = 0; x < n; x++) {
        cin >> current;
        l.push_back(current);
    }
    
    sort (e.begin(), e.begin() + e.size());
    sort (l.begin(), l.begin() + l.size());
    
    long total = 0;
    
    for (int x = 0; x < e.size(); x++) {
        total += e[x] * l[n - 1 - x];
    }
    
    if (n == 0) {
        total = 0;
    }
    
    cout << total;
    
}
