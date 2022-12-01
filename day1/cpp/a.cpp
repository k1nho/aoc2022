#include <cstdio>
#include <istream>
#include <iterator>
#include <vector>
#include <queue>
#include <stack> 
#include <math.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ios>
using namespace std;

void solve(string data) {
  
}

int main() {
  ifstream file("inputt.txt");
  string data  = "";
  int maxCalories = 0, elfPos = 0, ans = -1, curCalories = 0;
  vector<int> cals;

  while(getline(file, data)){
    if(data.empty()) {
      elfPos++;
      if(curCalories > maxCalories){
        ans = elfPos;
        maxCalories = curCalories;
      } 
      cals.push_back(curCalories);
      curCalories = 0;
      continue;
    }
    curCalories+= stoi(data);
  }

  cout << maxCalories << '\n';

  return 0;
  
}
