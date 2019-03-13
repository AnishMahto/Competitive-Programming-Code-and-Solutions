#include <iostream>
using namespace std;

int main () {
    int h;
    cin >> h;
    int m;
    cin >> m;
    
    int current;
    int total = 0; 
    
    for (int x = 0; x < m; x++) {
        cin >> current;
        if (current >= h) {
            total++;
        }
    }
    cout << total;
}
