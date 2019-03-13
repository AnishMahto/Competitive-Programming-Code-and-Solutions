#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int minMax[2002][2];

void modify (int pos, int val, bool greatest) {
    minMax[pos+1000][greatest] = val;
}
int query (int pos, bool greatest) {
    return minMax[pos+1000][greatest];
}

pair <double,double> slope (pair <int, int> p1, pair <int, int> p2) {
    double m = (double)(p2.second-p1.second)/(double)(p2.first-p1.first), b = (double)p2.second-m*(double)p2.first;
    return make_pair(m, b);
    
}

bool remMiddleUpperHull (pair <int, int> l, pair <int, int> m, pair <int, int> r) {
    //if middle point is below slope of left and right points, we toss the middle point
    pair <double, double> s = slope (l, r);
    if ((double)m.second < s.first*(double)m.first + s.second) {
        return true;
    } else {
        return false;
    }
}

bool remMiddleLowerHull (pair <int, int> l, pair <int, int> m, pair <int, int> r) {
    //if middle point is above slope of left and right points, we toss the middle point
    pair <double, double> s = slope (l, r);
    if ((double)m.second > s.first*(double)m.first + s.second) {
        return true;
    } else {
        return false;
    }
}

double length (pair <int, int> f, pair <int, int> s) {
    return sqrt((double)(f.first-s.first)*(f.first-s.first) + (double)(f.second-s.second)*(f.second-s.second));
}

double area (vector < pair <int, int> > p, pair <int, int> c) {
    double areaCnt = 0;
    for (int x = 1; x < p.size(); x++) {
        //make triangle with current point, previous point, and central point
        double A = length(p[x], p[x-1]), B = length(p[x], c), C = length(p[x-1], c);
        double S = (A + B + C)/2;
        areaCnt += sqrt (S*(S-A)*(S-B)*(S-C));
    }
    return areaCnt;
}

int main() {
    for (int x = -1000; x <= 1000; x++) {
        modify (x, -1001, 1);
        modify (x, 1001, 0);
    }
    int n, lx = 1001, gx = -1001, ly =  1001, gy = -1001;
    vector < pair <int, int> > upperHull, lowerHull;
    scanf ("%d", &n);
    for (int x = 0; x < n; x++) {
        int X, Y;
        scanf ("%d %d", &X, &Y);
        if (query (X, 1) <= Y) {
            modify(X, Y, 1);
        }
        if (query (X, 0) >= Y) {
            modify(X, Y, 0);
        }
        gx = max (gx, X);
        lx = min (lx, X);
        gy = max (gy, Y);
        ly = min (ly, Y);
    }
    //find points in the upperHull of optimal points;
    for (int x = lx; x <= gx; x++) {
        int val = query (x, 1);
        if (val==-1001) {
            continue;
        }
        if (upperHull.size()<=1) {
            upperHull.push_back(make_pair(x, val));
        } else {
            while (upperHull.size() >= 2 && remMiddleUpperHull (upperHull[upperHull.size()-1-1], upperHull.back(), make_pair(x, val))) {
                upperHull.pop_back();
            } 
            upperHull.push_back(make_pair(x, val));
        }
    }
    //find points in the lowerHull of optimal points;
    for (int x = lx; x <= gx; x++) {
        int val = query (x, 0);
        if (val==1001) {
            continue;
        }
        if (lowerHull.size()<=1) {
            lowerHull.push_back(make_pair(x, val));
        } else {
            while (lowerHull.size() >= 2 && remMiddleLowerHull (lowerHull[lowerHull.size()-1-1], lowerHull.back(), make_pair(x, val))) {
                lowerHull.pop_back();
            } 
            lowerHull.push_back(make_pair(x, val));
        }
    }
    vector < pair <int, int> > allValidPts;
    allValidPts.push_back(lowerHull[0]);
    for (int x = 0; x < upperHull.size(); x++) {
        allValidPts.push_back(upperHull[x]);
    }
    for (int x = lowerHull.size()-1; x >= 0; x--) {
        allValidPts.push_back(lowerHull[x]);
    }
    double totalArea = area(allValidPts, make_pair(((lx+gx)/2), (ly+gy)/2));
    cout << (int)(totalArea/50.0) << "\n";
    return 0;
}
