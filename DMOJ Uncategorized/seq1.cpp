#include <iostream>
#include <cstdio>
using namespace std;

long long MOD = 1e9+7;

//power function code borrowed from geeksforgeeks
long long power(long long y) {
    long long res = 1, x = 2;      // Initialize result
    long long p = MOD;
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}

int main() {
    long long n;
    scanf ("%lld", &n);
    if (n==0) {
        cout << 3 << "\n";
    } else if (n==1) {
        cout << 11 << "\n";
    } else {
        /*
        nth iteration has n rows, if we 0 base the rows
        0th row takes 2 characters; x=
        each element in last row takes 9 characters: x_{x}^{x}
        each element in rows inbetween take 7 characters: x_{}^{}
        the ith row has 2^i elements
        2^0 + 2^1 + 2^2 + 2^3 = 01111 = 10000 - 00001
        thus sum of first i powers of 2 = 2^(i+1) - 1
        */
        cout << 2 + ((power(n-1 /*sum of first n-2 rows, hence equals 2^(n-1)*/)*7)%MOD - 7*1 /*recall the -1 in the formula*/ + (power(n-1)*9)%MOD)%MOD << "\n";
    }
    return 0;
}
