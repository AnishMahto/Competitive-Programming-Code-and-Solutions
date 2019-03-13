#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int v[205] = {0};
    v['I']=1;
    v['V']=5;
    v['X']=10;
    v['L']=50;
    v['C']=100;
    v['D']=500;
    v['M']=1000;
    int sum = 0;
    for (int x=0; x<s.length(); x += 2) {
        if (x+3<s.length()) {
            if (v[s[x+3]]>v[s[x+1]]) {
                sum -= (s[x]-'0')*v[s[x+1]];
            } else {
                sum += (s[x]-'0')*v[s[x+1]];
            }
        } else {
            sum += (s[x]-'0')*v[s[x+1]];
        }
    }
    cout << sum << "\n";
}
