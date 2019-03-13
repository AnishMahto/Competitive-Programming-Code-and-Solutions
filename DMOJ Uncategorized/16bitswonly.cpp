#include <iostream>

using namespace std;

int main () {
    int tests;
    cin >> tests;
    
    long long a;
    long long b;
    long long p;
    for (int x = 0; x < tests; x++) {
        cin >> a;
        cin >> b;
        cin >> p;
        if (a * b == p) {
            cout << "POSSIBLE DOUBLE SIGMA" << endl;
        } else {
            cout << "16 BIT S/W ONLY" << endl;
        }
    }
}
