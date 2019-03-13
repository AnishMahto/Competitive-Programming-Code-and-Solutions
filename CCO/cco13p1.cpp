#include <iostream>
#include <cstdio>
#include <math.h>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

bool convertAndCheck (int a, int base) {
    deque <int> converted;
    int p[40];
    p[0] = 1;
    for (int x = 1; x <= log(a)/log(base); x++) {
        p[x] = p[x-1]*base;
    }
    int rem = a;
    for (int x = log(a)/log(base); x >= 0; x--) {
        converted.push_back(rem/p[x]);
        rem -= (rem/p[x]) * p[x];
    }
    while (true) {
        if (converted.size() <= 1) {
            return true;
        } else {
            if (converted.back() != converted.front()) {
                return false;
            } else {
                converted.pop_back();
                converted.pop_front();
            }
        }
    }
    return true;
}

int main()
{
    /*
    for bases x where x^2 > number:
    conversion = bx^1 + cx^0
    where b = c to be palindromic
    therefore = b*(x^1+x^0)
    hence only case where x^1 > number is palindromic is when (x^1+x^0)|number
    hence (x+1)|number
    hence look for positive divisors
    
    for bases x where x > number:
    conversion = cx^0, hence always palindromic
    however base is always < number
    */
    int X;
    scanf ("%d", &X);
    vector <int> ans;
    for (int x = 2; x <= sqrt (X); x++) {
        if (convertAndCheck(X, x)) {
            printf ("%d\n", x);
        }
        if (X%x==0 && X/x - 1 > sqrt (X)) {
            ans.push_back(X/x - 1);
        }
    }
    ans.push_back(X-1);
    sort (ans.begin(), ans.end());
    for (int x = 0; x < ans.size(); x++) {
        if (ans[x] > 1 && (x==0 || ans[x] != ans[x-1])) {
            printf ("%d\n", ans[x]);
        }
    }
    return 0;
}
