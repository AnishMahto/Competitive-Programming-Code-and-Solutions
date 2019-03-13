#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    vector <int> bowls;
    int current;
    for (int x = 0; x < 3; x++) {
        cin >> current;
        bowls.push_back(current);
    }
    sort (bowls.begin(), bowls.end());
    cout << bowls[1] << endl;
}
