#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main () {
    int n;
    cin >> n;
    vector <int> list(n);
    for (int x = 0; x < n; x++) {
        cin >> list[x];
    }
    sort (list.begin(), list.end());
    for (int x = 0; x < n; x++) {
        cout << list[x] << endl;
    }
    return 0;
}
