#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map <string, long long> food;

bool compare(const pair<long long, long long>&i, const pair<long long, long long>&j)
{
    if (i.first == j.first) {
      return i.second > j.second;
    }
    return i.first < j.first;
}

int main () {
  map <string, long long>::iterator it;
  long long n, temp;
  string name;
  cin >> n;
  for (int x = 0; x < n; x++) {
    cin >> name >> temp;
    food.insert(make_pair(name, temp));
  }
  cin >> n;
  vector < pair <long long, long long> > line(n);
  for (int x = 0; x < n; x++) {
    cin >> name >> line[x].first;
    it = food.find(name);
    line[x].second= it->second;
  }
  sort (line.begin(), line.end(), compare);
  long long energy = 0;
  long long pos = 0, eat = 0;
  for (int x = 0; x < n; x++) {
    if (line[x].first-pos <= energy || (line[x].first-pos == 0)) {
      eat++;
      energy -= (line[x].first-pos);
      pos = line[x].first;
      energy += line[x].second;
    } else {
      break;
    }
  }
  cout << eat << endl;
}
