#include <bits/stdc++.h>
using namespace std;

// LOST : 0pts [X,A]
// DRAW : 3pts [Y,B]
// WIN  : 6pts [Z,C]

char determineSymbol(char op, char me) {
  if(me == 'A') {
    return op == 'A' ? 'C' : op == 'B' ? 'A' : 'B';
  }
  else if(me == 'B') {
    return op == 'A' ? 'A' : op == 'B' ? 'B' : 'C';
  }
  else {
    return op == 'A' ? 'B' : op == 'B' ? 'C' : 'A';
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
      char matchRes = determineSymbol(op, me);
      totalScore +=  me == 'A' ? 0 : me == 'B' ? 3 : 6;
      totalScore += symbol[matchRes];
  }

  cout << "total score is: " << totalScore << '\n';
 
  return 0;
  
}
