#include <iostream>
using namespace std;

int main () {
    int a, b, c, d;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    
    if ( (b > c && a < d) || (a > d && b < c) ) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    
}
