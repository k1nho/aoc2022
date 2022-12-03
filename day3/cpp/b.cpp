#include <bits/stdc++.h>
using namespace std;


int solve(string r1, string r2, string r3) {
  int res = 0;
  unordered_map<char, int> freq;

  for(int i =0; i < r1.size(); i++) {
    if(freq.find(r1[i]) == freq.end()) freq[r1[i]]++; 
  }

  for(int i = 0; i < r2.size(); i++) {
    if(freq.find(r2[i]) != freq.end() && freq[r2[i]] == 1) freq[r2[i]]++;
  }

  for(int i = 0; i < r3.size(); i++) {
    if(freq.find(r3[i]) != freq.end() && freq[r3[i]] == 2) {
      if(r3[i] >= 'a' && r3[i] <= 'z') res+= r3[i]-'a'+1;
      else res+= r3[i] - 'A' +27;
      break;
    }
  }
  return res;

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string r1 = "" ,r2 = "", r3= "";
  int totalSum = 0;

  while(cin >> r1 >> r2 >> r3) {
    totalSum += solve(r1,r2,r3);
  }

  cout << "The total sum is: " << totalSum << '\n';
}
