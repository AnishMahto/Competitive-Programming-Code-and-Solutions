#include <iostream>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	vector < vector <int> > prereq(8);
	vector <int> answer;
	int check[8] = {0};
	prereq[7].push_back(1);
	prereq[4].push_back(1);
	prereq[1].push_back(2);
	prereq[4].push_back(3);
	prereq[5].push_back(3);
	int a, b;
	cin >> a >> b;
	while (a != 0 || b != 0) {
	    prereq[b].push_back(a);
	    cin >> a >> b;
	}
	bool end = false;
	while (end == false) {
	    end = true;
	    for (int x = 1; x < prereq.size(); x++) {
	        if (check[x] == 0) {
	            if (prereq[x].size() == 0) {
	                check[x] = 1;
	                answer.push_back(x);
	                end = false;
	                x = prereq.size();
	            } else {
	                for (int i = 0; i < prereq[x].size(); i++) {
	                    if (check[prereq[x][i]] != 1) {
	                        break;
	                    } else if (i == prereq[x].size() - 1) {
	                        check[x] = 1;
	                        answer.push_back(x);
	                        end = false;
	                        break;
	                        break;
	                    }
	                }
	            }
	        }
	    }
	}
	
	if (answer.size() != 7) {
	    cout << "Cannot complete these tasks. Going to bed." << endl;
	} else {
	    for (int x = 0; x < answer.size(); x++) {
	        cout << answer[x] << " ";
	    } cout << endl;
	}
	
	return 0;
}
