#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int reg = 1, sigSum = 0, cycle = 0, its = 220;
    string ins;
    unordered_set<int> st{20,60,100,140,180,220};
    while(cin >> ins || its--)  {
        if(ins == "noop") {
            cycle++;
            if(st.find(cycle) != st.end()) sigSum += reg*cycle;
        }
        else {
            int num;
            cin >> num;
            cycle++;
            if(st.find(cycle) != st.end()) sigSum += reg*cycle;
            cycle++;
            if(st.find(cycle) != st.end()) sigSum += reg*cycle;
            reg +=  num;
        }
    }

    cout << "total sum " << sigSum << '\n';
}
