#include <vector>
#include <iostream>
#include <ios>
#include <unordered_map>
#include <string>
#include <unordered_set>
using namespace std;

int reg = 1;
int cycle = 0;
int num;
string crtLine;

void drawChar() {
    // if the difference between the current cycle and the register value is at most 1 then we can draw
    crtLine += abs(cycle - reg) <= 1 ? '#' : '.';
    if(++cycle == 40) {
        cycle = 0;
        cout << crtLine << '\n';
        crtLine = string();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string ins = " ";

    while(cin >> ins)  {
       if(ins == "noop") drawChar();
       else{ 
           cin >> num;
           drawChar(); drawChar(); 
           reg += num;
       }
    }
}

