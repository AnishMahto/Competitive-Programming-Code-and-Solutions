#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int ottawa, victoria, edmonton, winnipeg, toronto, halifax, stjohns;
	cin >> ottawa;
	victoria = ottawa - 300;
	edmonton = ottawa - 200;
    winnipeg = ottawa - 100;
    
    if (victoria < 0) victoria = 2400 + victoria;
    if (edmonton < 0) edmonton = 2400 + edmonton;
    if (winnipeg < 0) winnipeg = 2400 + winnipeg;
    
    toronto = ottawa;
    halifax = ottawa + 100;
    stjohns = ottawa + 130;
    
    if (stjohns % 100 >= 60) stjohns -= 60, stjohns += 100;
    //all other cities should be fine since ottawa is guaranteed to have proper time. Only stjohns adds an extra 30, which might lead to this modification
    
    cout << ottawa % 2400 << " in Ottawa" << endl;
    cout << victoria % 2400 << " in Victoria" << endl;
    cout << edmonton % 2400 << " in Edmonton" << endl;
    cout << winnipeg % 2400 << " in Winnipeg" << endl;
    cout << toronto % 2400 << " in Toronto" << endl;
    cout << halifax % 2400 << " in Halifax" << endl;
    cout << stjohns % 2400 << " in St. John's" << endl;
    
	return 0;
}
