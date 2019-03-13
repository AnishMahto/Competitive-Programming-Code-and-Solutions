#include <iostream>
#include <vector>
using namespace std;

int maxScore, ways = 0;
int fish[3];
int cache[101][101][101] = {0};

int solve (int pos, vector <int> current) {
    int sum = current[0] * fish[0] + current[1] * fish[1] + current[2] * fish[2];
    if (sum <= maxScore && cache[current[0]][current[1]][current[2]] == 0 && sum != 0) {
        cache[current[0]][current[1]][current[2]] = 1;
        cout << current[0] << " Brown Trout, " << current[1] << " Northern Pike, " << current[2] << " Yellow Pickerel" << endl;
        ways++;
    }
    if (pos < 3) {
        for (int x = 0; x <= maxScore; x++) {
            current[pos] = x;
            if (current[0] * fish[0] + current[1] * fish[1] + current[2] * fish[2] <= maxScore) {
                solve (pos + 1, current);
            } else {
                break;
            }
        }
    }
    return 0;
}

int main() {
	// your code goes here
	cin >> fish[0] >> fish[1] >> fish[2] >> maxScore;
	vector <int> list(3);
	solve (0, list);
	cout << "Number of ways to catch fish: " << ways << endl;
	return 0;
}
