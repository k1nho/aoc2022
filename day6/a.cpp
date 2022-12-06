#include <bits/stdc++.h>
using namespace std;

int solve(string s) {
  // sliding window of size 4 until none of the characters are on the set
  unordered_set<char> st;
  int left = 0;
  for(int right =0; right < s.size(); right++) {
    while(st.find(s[right]) != st.end()) {
      st.erase(s[left]);
      left++; 
    } 
    st.insert(s[right]);
    if(right - left+ 1 == 4) return right;
  }

  return -1;

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string data = "";
  int ans;

  while(cin >> data) {
    ans = solve(data);
  }
  cout << "characters processed " << ans +1 << '\n';
}
