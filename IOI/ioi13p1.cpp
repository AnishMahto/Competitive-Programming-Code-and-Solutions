#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>
using namespace std;

vector < vector < pair <int, int> > > graph(100001);
vector <int> centers;
int centerWithMinimizedDistance, minimizedDistanceFromCenter = 0, greatestPaths[2][100001], greatestChildren[2][100001];
int tempNodeLP, diameter = -1, greatestCenter, greatestCenterDistance = 0;

int solveDiam (int pos, int par) {
  greatestPaths[0][pos] = greatestPaths[1][pos] = 0;
  for (int x = 0; x < graph[pos].size(); x++) {
    if (graph[pos][x].first != par) {
      int temp = graph[pos][x].second + solveDiam(graph[pos][x].first, pos);
      for (int i = 0; i < 2; i++) {
        if (greatestPaths[i][pos] < temp) {
          if (i == 0) {
            greatestPaths[1][pos] = greatestPaths[0][pos];
            greatestChildren[1][pos] = greatestChildren[0][pos];
          }
          greatestPaths[i][pos] = temp;
          greatestChildren[i][pos] = graph[pos][x].first;
          break;
        }
      }
    }
  }
  if (greatestPaths[0][pos] + greatestPaths[1][pos] > diameter) {
    diameter = greatestPaths[0][pos] + greatestPaths[1][pos];
    tempNodeLP = pos;
  }
  //cout << pos << ": " << greatestChildren[0][pos] << " " << greatestChildren[1][pos] << endl;
  return greatestPaths[0][pos];
}

int getCenter (int pos) {
  //cout << abs(greatestPaths[0][pos] - (diameter - greatestPaths[0][pos])) << endl;
  if (max(greatestPaths[0][pos], abs(/*greatestPaths[0][pos] - */(diameter - greatestPaths[0][pos]))) < minimizedDistanceFromCenter) {
    minimizedDistanceFromCenter = max(greatestPaths[0][pos], abs(/*greatestPaths[0][pos] - */(diameter - greatestPaths[0][pos])));
    centerWithMinimizedDistance = pos;
  }
  if (greatestChildren[0][pos] != -1) {
    //cout << greatestChildren[0][pos] << endl;
    getCenter (greatestChildren[0][pos]);
  }
  if (pos == tempNodeLP && greatestChildren[1][pos] != -1) {
    getCenter (greatestChildren[1][pos]);
  }
}

int travelTime(int N, int M, int L, int A[], int B[], int T[]) {
  memset(greatestPaths, -1, sizeof(greatestPaths));
  memset(greatestChildren, -1, sizeof(greatestChildren));
  for (int x = 0; x < M; x++) {
    graph[A[x]].push_back(make_pair(B[x], T[x]));
    graph[B[x]].push_back(make_pair(A[x], T[x]));
  }
  for (int x = 0; x < N; x++) {
    if (greatestPaths[0][x] == -1) {
      diameter = -1;
      tempNodeLP = x;
      centerWithMinimizedDistance = x;
      minimizedDistanceFromCenter = 2000000001;
      solveDiam(x, -1);
      getCenter(tempNodeLP);
      if (minimizedDistanceFromCenter > greatestCenterDistance) {
        greatestCenterDistance = minimizedDistanceFromCenter;
        greatestCenter = centerWithMinimizedDistance;
      }
      centers.push_back(centerWithMinimizedDistance);
    }
  }
  for (int x = 0; x < centers.size(); x++) {
    if (centers[x] != greatestCenter) {
      graph[centers[x]].push_back(make_pair(greatestCenter, L));
      graph[greatestCenter].push_back(make_pair(centers[x], L));
    }
  }
  diameter = -1;
  memset(greatestPaths, -1, sizeof(greatestPaths));
  memset(greatestChildren, -1, sizeof(greatestChildren));
  solveDiam(1, -1);
  return diameter;
}

int main () {
  //int temp[8] = {4, 2, 4, 3, 7, 1, 5, 3}, temp2[8] = {8, 2, 7, 11, 1, 3, 9, 6}, temp3[8] = {0, 8, 2, 5, 5, 1, 1, 10};
  //travelTime(12, 8, 2, temp3, temp2, temp);
}
