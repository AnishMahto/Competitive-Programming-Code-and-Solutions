#include <iostream>
#include <vector>

using namespace std;

int main () {
    
    int total;
    cin >> total;
    
    int take = 0;
    int serve = 0;
    
    vector <string> action;
    
    string current;
    cin >> current;
    
    while (current != "EOF") {
        action.push_back(current);
        cin >> current;
    }
    
    for (int x = 0; x < action.size(); x++) {
        if (action[x] != "CLOSE") {
            if (action[x] == "TAKE") {
                take++;
                total++;
            } else if (action[x] == "SERVE") {
                serve++;
            }
            if (total > 999) {
                total -= 999; 
            }
        } else {
            cout << take << " " << take - serve << " " << total << endl;
            take = 0;
            serve = 0;
        }
    }
    
}
