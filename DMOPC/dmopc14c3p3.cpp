#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int main () {
    int emp;
    cin >> emp;
    
    vector <string> name;
    vector <int> skill;
    string n;
    int current;
    
    for (int x = 0; x < emp; x++) {
        cin >> n;
        cin >> current;
        name.push_back(n);
        skill.push_back(current);
    }
    
    int new_emp;
    cin >> new_emp;
    
    int range, level;
    
    for (int a = 0; a < new_emp; a++) {
        cin >> level;
        cin >> range;
        
        int least = 10000000;
        string person;
        
        for (int x = 0; x < skill.size(); x++) {
            if (skill[x] >= level && skill[x] <= (level + range)) {
                if (abs(skill[x] - level) < least) {
                    least = abs(skill[x] - level);
                    person = name[x];
                }
            }
        }
        
        if (least == 10000000) {
            cout << "No suitable teacher!" << endl;
        } else {
            cout << person << endl;
        }
        
    }
    
}
