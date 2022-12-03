#include <bits/stdc++.h>
using namespace std;


int solve(string rucksack) {
  int N = rucksack.size(), res = 0;
  unordered_set<char> st;

  for(int i = 0; i < N/2; i++) {
    st.insert(rucksack[i]);
  }

  for(int i = N/2; i < N; i++) {
    if(rucksack[i] >= 'a' && rucksack[i] <= 'z'){
      if(st.find(rucksack[i]) != st.end()) {
        res += rucksack[i] - 'a' + 1;
        st.erase(rucksack[i]);
      }
    } 
    else {
      if(st.find(rucksack[i]) != st.end()) {
        res += rucksack[i] - 'A' + 27;
        st.erase(rucksack[i]);
      }
    }
  }

  cout << "res: " << res << '\n';
  return res;

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string rucksack = "";
  int totalSum = 0;

  while(cin >> rucksack) {
    totalSum += solve(rucksack);
  }

  cout << "The total sum is: " << totalSum << '\n';
}
