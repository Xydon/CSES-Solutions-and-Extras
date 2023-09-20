#include <bits/stdc++.h>
using namespace std; 

int main() {
  int n, k; cin >> n >> k; 
  map<int, vector<int>> mp; 
  for(int i = 1; i <= n; ++i) {
    int inp; cin >> inp;

    if(mp.count(k - inp)) {
      cout << mp.at(k-inp).at(0) << ' ' << i << endl; 
      return 0; 
    }

    mp[inp].push_back(i);
  }

  cout << "IMPOSSIBLE" << endl; 

  return 0; 
}