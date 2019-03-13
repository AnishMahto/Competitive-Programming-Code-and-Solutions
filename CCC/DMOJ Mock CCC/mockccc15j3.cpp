#include <iostream>
#include <vector>

using namespace std;

int main () {
    int t;
    cin >> t;
    
    vector <int> dif;
    
    int current;
    for (int x = 0; x < t; x++) {
        cin >> current;
        dif.push_back(current);
    }
    
    vector <int> del;
    
    for (int x = 0; x < dif.size(); x++) {
        for (int i = 0; i < dif.size(); i++) {
            if (i != x) {
                if (dif[i] == dif[x]) {
                    dif[i] = -1;
                }
            }
        }
    }
    
    int create = 0;
    for (int x = 0; x < dif.size(); x++) {
        if (dif[x] != -1) {
            create++;
        }
    }
    
    cout << create;
    
}
