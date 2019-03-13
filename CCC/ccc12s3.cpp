#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main() {
	// your code goes here
	vector <int> second;
	vector <int> first;
	int n, current, greatest = 0, secondGreatest = 0, big = 0;
	cin >> n;
	int freq[2000001] = {0};
	
	for (int x = 0; x < n; x++) {
	    scanf("%d", &current);
	    freq[current]++;
	    if (freq[current] > freq[greatest]) {
	        secondGreatest = greatest;
	        greatest = current;
	    } else if (freq[current] > freq[secondGreatest] && freq[current] != freq[greatest]) {
	        secondGreatest = current;
	    }
	    if (current > big) {
	        big = current;
	    }
	}
	
	first.push_back(greatest);
	second.push_back(secondGreatest);
	
	for (int x = 0; x <= big; x++) {
	    if (freq[x] == freq[greatest] && x != greatest && x != secondGreatest) {
	        first.push_back(x);
	    } else if (freq[x] == freq[secondGreatest] && x != greatest && x != secondGreatest) {
	        second.push_back(x);
	    }
	}
	sort (first.begin(), first.end());
	sort (second.begin(), second.end());
	cout << max(abs(first[first.size() - 1] - second[0]), abs(first[0] - second[second.size() - 1]) ) << endl;
	return 0;
}
