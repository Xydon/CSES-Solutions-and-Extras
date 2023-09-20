#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<pair<ll , ll >> ans(200001, {0,0});

void iter(vector<vector<int>>& tree, int src, int par) {
  
  ans[src].first = 0, ans[src].second = 0;
  vector<ll> pref, suff;

  bool leaf = 1; 
  for (int nbr : tree[src]) {
    if (nbr != par) {
      leaf = 0; 
      iter(tree, nbr, src);
    }
  }

  if (leaf or tree[src].size() == 0) return;


  for(int nbr : tree[src]) {
    if(nbr != par) {
      pref.push_back(max(ans[nbr].first, ans[nbr].second));
      suff.push_back(max(ans[nbr].first, ans[nbr].second));
    }
  }

  for(int i = 1; i < pref.size(); ++i){ 
    pref[i] += pref[i-1];
  }

  for(int i = (int)suff.size() - 2; i >= 0; --i) {
    suff[i] += suff[i+1];
  }

  ans[src].first = suff[0];

  int curr = 0; 
  for(int nbr : tree[src]) {
    if(nbr == par) continue; 

    ll left = (curr == 0) ? 0 : pref[curr-1];
    ll right = (curr == (int)suff.size() - 1) ? 0 : suff[curr+1];

    ans[src].second = max(ans[src].second, left + right + ans[nbr].first + 1);

    ++curr;
  }
  // cout << src << ' ' << ans[src].first << ' ' << ans[src].second << endl; 
}

int main() {
  // number of nodes 
  int n;
  cin >> n;

  vector<vector<int>> tree(n + 1);
  // n-1 edges 
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  iter(tree, 1, -1);

  cout << max(ans[1].first, ans[1].second) << endl;

  return 0;
}