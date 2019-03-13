#include <iostream>
using namespace std;

int main() {
	// your code goes here
    int n, d, k, tees = 0, current;
    char command;
    cin >> n >> d >> k;
    long long pieces[d + 2] = {0}, broken[d + 2] = {0};
    for (int x = 1; x <= n; x++) {
        cin >> command;
        if (command == 'T') {
            tees++;
        } else {
            cin >> current;
            if (pieces[tees] == 0) {
                pieces[tees] = current;
            } else {
                if (pieces[tees] * current > k) {
                    pieces[tees] = k + 1;
                } else {
                    pieces[tees] *= current;
                }
            }
        }
    }
    for (int x = d; x > 0; x--) {
        if (broken[x] == 0) {
            broken[x] = 1;
        }
        if (pieces[x] == 0) {
            if (x + 1 <= d) {
                pieces[x] = pieces[x + 1];
            }
        } else {
            if (x + 1 <= d && pieces[x + 1] != 0) {
                if (pieces[x] * pieces[x + 1] <= k) {
                    pieces[x] *= pieces[x + 1];
                } else {
                    pieces[x] = k + 1;
                }
            }
        }
        if (pieces[x] != 0) {
            if (broken[x] * pieces[x] < k) {
                broken[x] *= pieces[x];
            } else {
                broken[x] = k + 1;
            }
        }
    }
    for (int x = 1; x <= d; x++) {
        if (broken[x] > k) {
            cout << "dust" << endl;
        } else {
            cout << broken[x] << endl;
        }
    }
	return 0;
}
