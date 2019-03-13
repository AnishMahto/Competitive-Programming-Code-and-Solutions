#include <iostream>
#include <vector>
using namespace std;

int main () {
    int num;
    cin >> num;
    
    int current;
    int prevSum = 0;
    
    int unknown;
    
    for (int a = 0; a < num; a++) {
        cin >> current;
        unknown = current * (a + 1) - prevSum;
        prevSum += unknown;
        cout << unknown << " ";
    }
    
}
