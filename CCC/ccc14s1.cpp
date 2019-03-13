#include <iostream>
#include <vector>
using namespace std;

int main () {
    int n;
    cin >> n;
    
    vector <int> friends;
    
    for (int x = 1; x <= n; x++) {
        friends.push_back(x);
    }
    
    int rounds;
    cin >> rounds;
    
    int interval;
    vector <int> removal;
    
    for (int x = 0; x < rounds; x++) {
        cin >> interval;
        
        for (int i = interval - 1; i < friends.size(); i+=interval - 1) {
            friends.erase(friends.begin() + i);
        }
        
    }
    
    for (int x = 0; x < friends.size(); x++) {
        cout << friends[x] << endl;
    }
    
}
