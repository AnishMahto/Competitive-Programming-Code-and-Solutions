#include <iostream>
#include <map>
using namespace std;

map <string, string> translate;

int main() {
	// your code goes here
	string word;
	map <string, string>::iterator it;
	translate["CU"] = "see you";
	translate[":-)"] = "I'm happy";
	translate[":-("] = "I'm unhappy";
	translate[";-)"] = "wink";
	translate[":-P"] = "stick out my tongue";
	translate["(~.~)"] = "sleepy";
	translate["TA"] = "totally awesome";
	translate["CCC"] = "Canadian Computing Competition";
	translate["CUZ"] = "because";
	translate["TY"] = "thank-you";
	translate["YW"] = "you're welcome";
	translate["TTYL"] = "talk to you later";
	cin >> word;
	while (word != "TTYL") {
	    it = translate.find(word);
	    if (it!=translate.end()) {
	        cout << it->second << endl;
	    } else {
	        cout << word << endl;
	    }
	    cin >> word;
	}
	
	cout << "talk to you later" << endl;
	
	return 0;
}
