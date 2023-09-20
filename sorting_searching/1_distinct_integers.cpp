#include <bits/stdc++.h>
using namespace std; 

int main() {
  int n; cin >> n; 
  map<int, int> ump; 
  for(int i = 0; i < n; ++i) {
    int a; cin >> a; 
    ump[a]++;
  }
  cout << ump.size() << endl; 
  return 0; 
}
