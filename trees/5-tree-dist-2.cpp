#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> ans, sub, sz;

void iter(vector<vector<int>> & tree, int src, int par) {
  sz[src] = 1; 
  sub[src] = 0;
  for(int nbr : tree[src]) {
    if(nbr != par) {
      iter(tree, nbr, src);
      sz[src] += sz[nbr];
      sub[src] += sub[nbr] + sz[nbr];
    } 
  }
}

void solve(vector<vector<int>> & tree, int src, int par, ll partial) {
  // re-rooting 
  ans[src] = sub[src] + (partial + ((ll)tree.size() - 1) - sz[src] );

  for(int nbr : tree[src]) {
    if(nbr != par) {
      // partial ans 
      solve(tree, nbr, src, ans[src] - (sub[nbr] + sz[nbr]));
    }
  }
}

int main() {
  int n;
  cin >> n;

  ans.resize(n + 1);
  sub.resize(n + 1);
  sz.resize(n + 1);

  vector<vector<int>> tree(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  iter(tree, 1, 0);
  solve(tree, 1, 0,0 );

  for(int i = 1; i <= n; ++i) {
    cout << ans[i] << ' ';
  }

  return 0;
}