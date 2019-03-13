#include <vector>
#include <iostream>
#include <string.h>
using namespace std;

long long coefficient[11] = {0};
long long multiplier = 1, out = 1;
//x^10, x^9...x^0
vector < long long > terms;

long long solve (int pos, int exs, long long constant) {
    if (pos == terms.size()) {
        coefficient[exs] += constant;
    } else {
        if (pos == 0) {
            solve (pos + 1, exs + 1, multiplier);
        } else {
            solve (pos + 1, exs + 1, constant);
        }
        solve (pos + 1, exs, constant * terms[pos]);
    }
    return 0;
}


int main() {
	// your code goes here
	int n;
	long long current, temp, ex;
	long long y;
	cin >> n;
	for (int x = 0; x < n; x++) {
	    memset(coefficient, 0, sizeof(long long)*11);
	    out = 1; multiplier = 1;
	    cin >> current;
	    terms.clear();
	    for (int i = 0; i < current; i++) {
	        cin >> temp;
	        terms.push_back(temp * -1);
	    }
	    cin >> ex >> y;
	    for (int i = 0; i < terms.size(); i++) {
	        out *= (ex + terms[i]);
	    }
	    multiplier = y/out;
	    terms[0] *= multiplier;
	    solve (0, 0, 1);
	    for (int i = 10; i >= 0; i--) {
	        if (coefficient[i] != 0) {
	            cout << coefficient[i] << " ";
	        }
	    } cout << endl;
	}
	return 0;
}
