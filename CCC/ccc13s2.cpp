#include <iostream>
#include <queue>
using namespace std;

int main() {
	// your code goes here
	queue <int> bridge;
	int w, n, current, sum = 0, cars = 0;
	cin >> w >> n;
	if (n <= 4) {
	    for (int x = 0; x < n; x++) {
	        cin >> current;
	        if (sum + current <= w) {
	            sum += current;
	            cars++;
	        } else {
	            break;
	        }
	    }
	    cout << cars << endl;
	} else {
	    for (int x = 0; x < n; x++) {
	        if (bridge.size() == 4) {
	            sum -= bridge.front();
	            bridge.pop();
	        }
	        cin >> current;
	        if (current + sum <= w) {
	            sum += current;
	            bridge.push(current);
	            cars++;
	        } else {
	            break;
	        }
	    }
	    cout << cars << endl;
	}
	return 0;
}
