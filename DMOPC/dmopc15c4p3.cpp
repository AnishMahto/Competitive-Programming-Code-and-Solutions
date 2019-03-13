#include <iostream>
#include <vector>
using namespace std;

bool lethal = false;

int solve (vector <int> attacks, int taunt, int health) {
    
    vector <int> temp = attacks;
    
    for (int x = 0; x < attacks.size(); x++) {
        
        if (taunt <= 0) {
            
            if (health - attacks[x] <= 0) {
                lethal = true;
                return 0;
            } else {
                temp.erase(temp.begin() + x);
                solve (temp, taunt, health-attacks[x]);
                temp = attacks;
            }
            
        } else {
            
            temp.erase(temp.begin() + x);
            solve (temp, taunt-attacks[x], health);
            temp = attacks;
            
        }
        
    }
    
}

int main() {
	// your code goes here
	int games;
	cin >> games;
	
	int minions, oppMinion, oppHealth;
	vector <int> attacks;
	
	int current;
	for (int x = 0; x < games; x++) {
	    
	    lethal = false;
	    
	    cin >> minions;
	    for (int i = 0; i < minions; i++) {
	        cin >> current;
	        attacks.push_back(current);
	    }
	    cin >> oppMinion;
	    cin >> oppHealth;
	    
	    solve (attacks, oppMinion, oppHealth);
	    
	    if (lethal) {
	        cout << "LETHAL" << endl;
	    } else {
	        cout << "NOT LETHAL" << endl;
	    }
	    attacks.clear();
	}
	
	return 0;
}
