#include <iostream>
using namespace std;

int main () {
    int days;
    cin >> days;
    
    int logs;
    int current;
    int total = 0;
    for (int x = 0; x < days; x++) {
        total = 0;
        
        cin >> logs;
        
        for (int i = 0; i < logs; i++) {
            cin >> current;
            total += current;
        }
        if (total == 0) {
            cout << "Weekend" << endl;
        } else {
            cout << "Day " << x + 1 << ": " << total << endl; 
        }
    }
    
    
}
