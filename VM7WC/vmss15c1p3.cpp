#include <iostream>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	float slope, intercept;
	float x1, y1, x2, y2;
	cin >> x1;
	cin >> y1;
	cin >> x2;
	cin >> y2;
	
	float xRange = x2 - x1;
	
	slope = (y2 - y1)/(x2 - x1);
	intercept = y1 - slope*x1;
	
	int n;
	cin >> n;
	
	float a, b, c;
	vector < vector <float> > equations;
	vector <float> temp;
	
	for (int x = 0; x < n; x++) {
	    temp.clear();
	    cin >> a;
	    cin >> b;
	    cin >> c;
	    temp.push_back(a);
	    temp.push_back(b);
	    temp.push_back(c);
	    equations.push_back(temp);
	}
	
	int roads = 0;
	
	int value;
	for (int x = 0; x < equations.size(); x++) {
	    value = (intercept + (equations[x][2]/equations[x][1]))/(-1*(equations[x][0]/equations[x][1]) - slope);
	    if ( (x1 <= value && x2 >= value) || (x1 >= value && x2 <= value) ) {
	        roads++;
	    }
	}
	
	cout << roads << endl;
	
	return 0;
}
