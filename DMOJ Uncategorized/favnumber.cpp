#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	vector <int> numbers;
	int n, q, current;
	scanf("%d", &n);
	
	for (int x = 0; x < n; x++) {
	    scanf("%d", &current);
	    numbers.push_back(current);
	}
	
	sort (numbers.begin(), numbers.end());
	
	scanf ("%d", &q);
	
	vector <int>::iterator upper, lower;
	
	for (int r = 0; r < q; r++) {
	    scanf ("%d", &current);
	    
	    lower = lower_bound (numbers.begin(), numbers.end(), current);
        upper = upper_bound (numbers.begin() + (lower - numbers.begin()), numbers.end(), current);
        
        if (numbers[lower - numbers.begin()] == current) {
            printf ("%d %d\n", current, (upper - numbers.begin()) - (lower - numbers.begin()));
        } else {
            printf ("%d ", numbers[upper - numbers.begin()]);
            int temp = upper - numbers.begin();
            upper = upper_bound (numbers.begin() + temp, numbers.end(), numbers[upper - numbers.begin()]);
            printf ("%d\n", (upper - numbers.begin()) - (lower - numbers.begin()));
        }
        
    }
    
	return 0;
}
