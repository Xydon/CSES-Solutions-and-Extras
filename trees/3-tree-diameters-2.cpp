#include <bits/stdc++.h>
using namespace std;
#define ll long long


int mx_dist = 0, node = 0; 
void iter(vector<vector<int>> & tree, int src, int par, int pl) {
  if(mx_dist < pl) {
    mx_dist = pl; 
    node = src; 
  }

  for(int nbr : tree[src]) {
    if(nbr != par) iter(tree, nbr, src, pl+1);
  }
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

  iter(tree, 1, 0, 0);
  mx_dist = 0; 
  iter(tree, node, 0, 0);

  cout << mx_dist << endl; 

  return 0;
}