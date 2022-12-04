#include <bits/stdc++.h>
using namespace std;

int solve(int x1, int y1, int x2, int y2) {
  return (x1 <= x2 && y1 >= y2) || (x2 <= x1 && y2 >= y1);
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int total = 0;
  int x1, y1, x2, y2;
  while(cin >> x1 >> y1 >> x2 >> y2) {
    total += solve(x1, y1, x2, y2);
  }
  
  cout << "total overlapping pairs " << total << '\n';
  return 0;
}
