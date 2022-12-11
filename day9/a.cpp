#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    char dir = 'a';
    int scalar = 0;
    unordered_set<int> st;
    pair<int, int> headPos = {0,0};
    pair<int, int> tailPos = {0,0};
    while(cin >> dir >> scalar) {
        while(scalar--){
            if(dir == 'U') {headPos.first+=1;}
            else if(dir == 'D') { headPos.first-=1;} 
            else if(dir == 'R') { headPos.second+=1;}
            else {headPos.second-=1;}
            pair<int ,int> delta = {headPos.first - tailPos.first, headPos.second - tailPos.second};
            if(abs(delta.first) == 2 && abs(delta.second) == 0) {tailPos.first+=delta.first/2;}
            else if(abs(delta.first) == 2 && abs(delta.second) == 1) {tailPos.first+=delta.first/2; tailPos.second+= delta.second;}
            else if(abs(delta.first) == 0 && abs(delta.second) == 2) {tailPos.second+=delta.second/2;}
            else if(abs(delta.first) == 1 && abs(delta.second) == 2) {tailPos.first+=delta.first; tailPos.second+=delta.second/2;} 
            st.insert(tailPos.first*100000 + tailPos.second);

                    }
    }

    cout << "total cells visited by tail " << st.size() << '\n';
}
