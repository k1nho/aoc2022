#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

pii simulateMotion(pii H, pii T) {
    int dr = H.first - T.first;
    int dc = H.second - T.second;

    if(abs(dr) <= 1 && abs(dc) <= 1){}
    else if (abs(dr) >= 2 && abs(dc) >= 2) {
        T.first = T.first < H.first ? H.first - 1 : H.first + 1;
        T.second = T.second < H.second ? H.second - 1 : H.second + 1;
    }
    else if(abs(dr) >= 2) {
        T.first = T.first < H.first ? H.first - 1 : H.first + 1;
        T.second = H.second;
    }
    else if(abs(dc) >= 2){
        T.second = T.second < H.second ? H.second - 1 : H.second + 1;
        T.first = H.first;
    }
    return T;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    char dir; int scalar;
    unordered_map<char, int> DR{{'U', -1}, {'D', 1}, {'R', 0}, {'L', 0}};
    unordered_map<char, int> DC{{'U', 0}, {'D', 0}, {'R', 1}, {'L', -1}};
    unordered_set<int> st;
    vector<pii> knots(9, {0,0});
    st.insert(0);
    pii H = {0,0};
    

    while(cin >> dir >> scalar) {
        while(scalar--) {
            H = {H.first + DR[dir], H.second + DC[dir]};
            knots[0] = simulateMotion(H, knots[0]);
            
            for(int i = 1; i < 9; i++) {
                knots[i] = simulateMotion(knots[i-1], knots[i]); 
            }
            st.insert(knots[8].first * 10000 + knots[8].second); 
        } 
    }

    cout << "total cells visited by tail " << st.size() << '\n';
}
