#include <bits/stdc++.h>
using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  unordered_map<int , stack<char>> mp;
  
  string data = "";
  int idx = 1;

  while(cin >> data && data != "a") {
    cout << data << '\n';
    for(int i = data.size() -1; i >= 0; i--) {
      mp[idx].push(data[i]);
    }
    idx++;
  }
  
  int N, idx1, idx2;
  while(cin >> N >> idx1 >> idx2) {
    stack<char> temp;
    while(N--) {
      char ch = mp[idx1].top(); mp[idx1].pop();
      temp.push(ch);
    }
    while(!temp.empty()) {
      mp[idx2].push(temp.top()); temp.pop();
    }
  }
  
  string ans = "";
  for(auto [k,v] : mp ){ 
    ans.push_back(v.top());
  }

  reverse(ans.begin(), ans.end());
  cout << "The top crates are " <<  ans << '\n';
}
