#include <bits/stdc++.h>
using namespace std;

// LOST : 0pts
// DRAW : 3pts
// WIN  : 6pts
// ROCK: [A, X] 1 pt
// PAPER: [B, Y] 2 pt
// SCISSORS : [C, Z] 3 pt

int determineMatchup(char op, char me) {
  if(me == 'A') {
    return op == 'A' ? 0 : op == 'B' ? -1 : 1;
  }
  else if(me == 'B') {
    return op == 'B' ? 0 : op == 'C' ? -1 : 1;
  }
  else {
    return op == 'C' ? 0 : op == 'A' ? -1 : 1;
  }
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  char op, me;
  unordered_map<char, char> mp{{'X' , 'A'}, {'Y', 'B'}, {'Z', 'C'}};
  unordered_map<char, int> symbol{{'A' , 1}, {'B', 2}, {'C', 3}};
  int totalScore = 0;
  
  while(cin >> op >> me) {
      me = mp[me];
      int matchRes = determineMatchup(op, me);
      totalScore +=  matchRes == 0 ? 3 : matchRes == 1 ? 6 : 0;
      totalScore += symbol[me];
  }

  cout << "total score is: " << totalScore << '\n';
 
  return 0;
  
}
