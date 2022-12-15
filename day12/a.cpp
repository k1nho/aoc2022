#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <ios>
#include <algorithm>
#include <math.h>
using namespace std;

typedef pair<int, pair<char, pair<int, int>>> pii;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<char>> m;
    queue<pii> q;
    int row = 0;

    string s;
    while(cin >> s) {
        vector<char> temp;
        for(auto ch : s) {
            if(ch == 'S') {
                temp.push_back('a');
                q.push({0, {'a', {row, 0}}});
                continue;

            }
            temp.push_back(ch);
        }
        row++;
        m.push_back(temp);
    }
    
    int M = m.size(), N = m[0].size();
    vector<pair<int, int>> dirs{{1,0}, {-1,0}, {0,-1}, {0,1}};

    auto checkBounds = [&](int r, int c) -> bool {
        if(r >= 0 && r < M && c >= 0 && c < N) return true;
        return false;
    };

    auto checkTransition = [&](char from, char to) -> bool {
        if(from - to >= 0) return true;
        else if(from - to == -1) return true;
        return false;
    };

    bool notFound = true;
    while(!q.empty() && notFound) {
        for(int i = 0; i < q.size(); i++ ){
            auto [x,y] = q.front().second.second;
            char nodeval = q.front().second.first;
            int dist = q.front().first;
            m[x][y] = '*';
            if(nodeval == 'E') {cout << "total moves to get to target " << dist << '\n'; notFound = false; break;}
            q.pop();

            for(auto p : dirs) {
                int nr = x + p.first;
                int nc = y + p.second;
                
                if(checkBounds(nr , nc)) {
                    char ch = m[nr][nc] == 'E' ? 'z' : m[nr][nc];
                    if(checkTransition(nodeval, ch) && m[nr][nc] != '*'){
                        q.push({dist +1, {m[nr][nc] , {nr, nc}}});
                        m[nr][nc] = '*';
                    }
                }
            }
        }
    }

}
