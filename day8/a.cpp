#include <bits/stdc++.h>
using namespace std;


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
    vector<pair<int, int>> dirs = {{0,1}, {0,-1}, {1, 0}, {-1, 0}};
    vector<vector<bool>> n(M, vector<bool>(N, false));

    for(int i = 0; i < M; i++) {
        n[i][0] = true;
        n[i][N-1] = true;
    }

    for(int i = 0; i < N; i++) {
        n[0][i] = true;
        n[M-1][i] = true;
    }
    
    int maxTreeRight = 0, maxTreeLeft = 0;
    // traverse outside to inside check the 4 directions
    for(int row = 1; row < M-1; row++) {
        for(int col = 0; col < N-1; col++) {
            if(col == 0) {
                maxTreeLeft = m[row][col];
                maxTreeRight = m[row][N-col-1];
                continue;
            }
            if(m[row][col] > maxTreeLeft){
                maxTreeLeft = m[row][col];
                n[row][col] = true;
            }
            if(m[row][N-col-1] > maxTreeRight) {
                maxTreeRight = m[row][N-col-1];
                n[row][N-col-1] = true;
            }
        }
    }

    maxTreeRight = 0, maxTreeLeft = 0;
    for(int col = 1; col < N-1; col++) {
        for(int row = 0; row < N-1; row++) {
            if(row == 0) {
                maxTreeLeft = m[row][col];
                maxTreeRight = m[M-row-1][col];
                continue;
            }
            if(m[row][col] > maxTreeLeft){
                maxTreeLeft = m[row][col];
                n[row][col] = true;
            }
            if(m[M-row-1][col] > maxTreeRight) {
                maxTreeRight = m[M-row-1][col];
                n[M-row-1][col] = true;
            }
        }
    }

    int total = 0;
    for(int row =0; row < M; row++) {
        for(int col =0; col < N; col++) {
            if(n[row][col]) total++;
        }
    }

    cout << "the total is " << total << '\n';

}
