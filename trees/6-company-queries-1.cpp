#include <bits/stdc++.h>
using namespace std; 

#define ll long long

int main() {
  int n, q; cin >> n >> q; 
  vector<vector<int>> par(n+1, vector<int>(20, -1));
  for(int i = 2 ; i <= n; ++i) {
    cin >> par[i][0]; 
  }

  for(int i = 1; i <= n; ++i){ 
    for(int j = 1; j <= 19; ++j) {
      par[i][j] = (par[i][j-1] == -1) ? -1 : par[par[i][j-1]][j-1];
    }
  }

  while(q--) {
    int a, b; cin >> a >> b;

    for(int i = 0; i <= 19; ++i) {
      int mask = 1 << i; 
      if(b & mask) {
        a = par[a][i];
        if(a == -1) break;
      }
    }

    cout << a << '\n';
  }

  return 0; 
}
