#include <iostream>
using namespace std;

int main () {
    int t;
    cin >> t;
    
    int current;
    
    for (int x = 0; x < t; x++) {
        
        int sum = 1;
        
        cin >> current;
        
        for (int i = 2; i <= (current / 2); i++) {
            if (current % i == 0) {
                sum += i;
            }
        }
        
        if (sum == current) {
            cout << current << " is a perfect number." << endl;
        } else if (sum > current) {
            cout << current << " is an abundant number." << endl;
        } else if (sum < current) {
            cout << current << " is a deficient number." << endl;
        }
        
    }
    
}
