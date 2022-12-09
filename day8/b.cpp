#include <bits/stdc++.h>
using namespace std;

int findMax(int row, int col, vector<vector<int>> &m, char mode) {
    int ans = 0;
    int val = m[row][col];
    switch (mode) {
        case 'u':
            row--;
            while(row >= 0 && val > m[row][col]){row--, ans++;}
            if(row >= 0) ans++;
            break;
        case 'd':
            row++;
            while(row < m.size() && val > m[row][col]) {row++, ans++;}
            if(row < m.size()) ans++;
            break;
        case 'l':
            col--;
            while(col >= 0 && val > m[row][col]) {col--, ans++;}
            if(col >= 0) ans++;
            break;
        default:
            col++;
            while(col < m[0].size() && val > m[row][col]) {col++, ans++;}
            if(col < m[0].size()) ans++;
    }

    return ans == 0 ? 1 : ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string row ="";
    vector<vector<int>> m;
    while(cin >> row) {
        vector<int> temp;
        for(char ch: row) {
            temp.push_back(ch - '0');
        }
        m.push_back(temp);
    }
    
    int M = m.size(), N = m[0].size();
    int best = -1;

    for(int row = 0; row < M; row++) {
        for(int col = 0; col < N; col++) {
            if(row == 0 || col == 0 || row == M-1 || col == M-1) continue;
            int up = findMax(row, col, m, 'u'); 
            int down = findMax(row, col, m, 'd'); 
            int left = findMax(row, col, m, 'l'); 
            int right = findMax(row, col, m, 'r'); 
            best = max(best, up*down*left*right);
        }
    } 

    cout << "the best is " << best << '\n';
    return 0;
}



