#include <iostream>
using namespace std;

int main () {
    int w;
    int l;
    cin >> w;
    cin >> l;
    
    int tile;
    cin >> tile;
    
    int tiles = 0;
    
    while (w >= tile) {
        w -= tile;
        tiles++;
    }
    int multiplier = 0;
    while (l >= tile) {
        l -= tile;
        multiplier++;
    }
    
    cout << tiles * multiplier;
    
}
