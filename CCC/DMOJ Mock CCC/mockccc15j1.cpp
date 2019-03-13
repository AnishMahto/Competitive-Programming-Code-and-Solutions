#include <iostream>

using namespace std;

int main () {
    string first;
    cin >> first;
    string second;
    cin >> second;
    
    if (second.length() == 7 && first.length() == 3) {
        if ((first == "647" || first == "437")) {
            cout << "valueless";
        } else if (first == "416") {
            cout << "valuable";
        } else {
            cout << "invalid";
        }
    } else {
        cout << "invalid";
    }
    
}
