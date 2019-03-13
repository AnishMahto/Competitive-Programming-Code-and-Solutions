#include <iostream>
using namespace std;

int choices[4];
int total, ways = 0;
int bestChoice = -1;

int solve (int left, int pos, int chosen[]) {
    if (left == 0) {
        cout << "# of PINK is " << chosen[0] << " # of GREEN is " << chosen[1] << " # of RED is " << chosen[2] << " # of ORANGE is " << chosen[3] << endl;
        ways++;
        if (chosen[0] + chosen[1] + chosen[2] + chosen[3] < bestChoice || bestChoice == -1) {
            bestChoice = chosen[0] + chosen[1] + chosen[2] + chosen[3];
        }
        return 0;
    } else if (pos > 3) {
        return 0;
    } else if (left < 0) {
        return 0;
    }
    
    if (pos < 4) {
        solve (left, pos + 1, chosen);
    }
    
    if (left - choices[pos] >= 0) {
        chosen[pos]++;
        solve (left - choices[pos], pos, chosen);
        chosen[pos]--;
    }
    
    return 0;
}

int main() {
	// your code goes here
	int temp[4] = {0};
	cin >> choices[0] >> choices[1] >> choices[2] >> choices[3] >> total;
	solve (total, 0, temp);
	cout << "Total combinations is " << ways << "." << endl;
	cout << "Minimum number of tickets to print is " << bestChoice << "." << endl;
    return 0;
}
