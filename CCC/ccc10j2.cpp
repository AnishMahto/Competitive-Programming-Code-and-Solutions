#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int a, b, c, d, s, byron = 0, nikky = 0;
	cin >> a >> b >> c >> d >> s;
	
	int stepNikky = 0, stepByron = 0;
	bool prevN = true, prevB = true;
	
	for (int x = 1; x <= s; x++) {
	    if (prevN == true) {
	        nikky ++;
	    } else if (prevN == false) {
	        nikky --;
        }
	    if (prevB == true) {
	        byron ++;
	    } else if (prevB == false) {
	        byron --;
        }
	    stepByron++;
	    stepNikky++;
	    if (prevN == true && stepNikky == a) {
	        prevN = false;
	        stepNikky = 0;
	    } else if (prevN == false && stepNikky == b) {
	        prevN = true;
	        stepNikky = 0;
	    }
	    if (prevB == true && stepByron == c) {
	        prevB = false;
	        stepByron = 0;
	    } else if (prevB == false && stepByron == d) {
	        prevB = true;
	        stepByron = 0;
	    }
	}
	
	
	if (nikky > byron) {
	    cout << "Nikky" << endl;
	} else if (byron > nikky) {
	    cout << "Byron" << endl;
	} else {
	    cout << "Tied" << endl;
	}
	
	return 0;
}
