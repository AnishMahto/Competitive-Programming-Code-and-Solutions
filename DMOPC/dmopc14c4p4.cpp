#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map <string, bool> check;

int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    unordered_map <string, bool>::iterator it;
    string message, code = "HAILHYDRA";
    cin >> message;
    for (int x = 0; x < message.length()-8; x++) {
        if (message[x] == message[x+4] && message[x+1]==message[x+8]) {
            string tmp = "";
            for (int i = x; i <= x+8; i++) {
                tmp += message[i];
            }
            check.insert (make_pair(tmp, false));
        }
    }
    int n;
    char organized[27] = {0};
    string key;
    cin >> n;
    for (int x = 0; x < n; x++) {
        cin >> key;
        for (int i = 0; i < key.length(); i++) {
            organized[(int)key[i]-65] = (char)(65+i);
        }
        string checkStr = "";
        for (int i = 0; i < code.length(); i++) {
            checkStr += key[(int)code[i]-65];
        }
        it = check.find (checkStr);
        if (it != check.end()) {
            for (int i = 0; i < message.length(); i++) {
                message[i] = organized[(int)message[i]-65];
            }
            cout << message << "\n";
            return 0;
        }
    }
    cout << "KeyNotFoundError" << endl;
    return 0;
}
