#include <bits/stdc++.h>
using namespace std;

#define ll long long

int gmx = 0; 

int height(vector<vector<int>> & tree, int src, int par) {
  int mx = 0, smx = 0; 
  bool leaf = 1; 
  for(int nbr : tree[src]) {
    if(nbr == par) continue; 
    leaf = 0; 
    int ht = height(tree, nbr, src); 
    if(ht > mx) {
      smx = mx; 
      mx = ht; 
    } else if(ht > smx) {
      smx = ht; 
    }
  }

  if(leaf) return -1; 

  int addFactor = tree[src].size() >= 2 ? 2 : 1;
  gmx = max(gmx, mx + smx + addFactor); 

  return mx + 1; 
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> tree(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  height(tree, 1, 0);
  cout << gmx << endl; 

  return 0;
}