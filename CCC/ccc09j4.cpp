#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int main() {
	// your code goes here
	vector <string> lines;
	for (int x = 0; x < 6; x++) {
	    lines.push_back("");
	}
	vector <string> words;
	words.push_back("WELCOME");
	words.push_back("TO");
	words.push_back("CCC");
	words.push_back("GOOD");
	words.push_back("LUCK");
	words.push_back("TODAY");
	int w;
	cin >> w;
	int pos = 0;
	
	for (int x = 0; x < words.size(); x++) {
	    if (lines[pos].length() == 0) {
	        lines[pos] += words[x];
	        if (lines[pos].length() < w) {
	            lines[pos] += ".";
	        }
	    }
	    else if (lines[pos].length() + words[x].length() + 1 <= w && (x != words.size() - 1 && words[x + 1].length() + words[x].length() + 1 + lines[pos].length() <= w)) {
	        lines[pos] += words[x];
	        lines[pos] += ".";
	    }
	    else if (lines[pos].length() + words[x].length() <= w) {
	        lines[pos] += words[x];
	        pos++;
	    }
	    else {
	        pos++;
	        x--;
	    }
	}
	
	for (int x = 0; x < lines.size(); x++) {
	    bool periods = false;
	    for (int i = 0; i < lines[x].length(); i++) {
	        if (lines[x][i] == '.') {
	            periods = true;
	            break;
	        }
	    }
	    if (lines[x].length() != w && lines[x].length() != 0) {
	        int temp = lines[x].length();
	        while (temp != w) {
	            if (periods) {
	            for (int i = 0; i < lines[x].length(); i++) {
	                if (temp + 1 <= w && lines[x][i] == '.' && lines[x][i - 1] != '.') {
	                    lines[x].insert(i, ".");
	                    temp++;
	                }
	            }
	            } else {
	                lines[x] += ".";
	                temp++;
	            }
	        }
	    }
	}
	
	for (int x = 0; x < lines.size(); x++) {
	    if (lines[x].length() != 0) {
	        cout << lines[x] << endl;
	    }
	}
	
	return 0;
}
