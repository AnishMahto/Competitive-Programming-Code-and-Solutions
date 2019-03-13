#include <iostream>
using namespace std;

int main() {
	// your code goes here
    
    string converted = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string decrypt = "0123456789ABCDEFGHIJKLMNOP";
    
    string code;
    cin >> code;
    
    for (int x = 0; x < code.length(); x++) {
        for (int i = 0; i < decrypt.size(); i++) {
            if (code[x] == decrypt[i]) {
                if (decrypt[i] == '0') {
                    cout << 9;
                } else {
                    cout << converted[i - 1];
                }
                i = decrypt.size();
            }
        }
    }
    
	return 0;
}
