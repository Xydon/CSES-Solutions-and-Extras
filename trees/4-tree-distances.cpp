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

vector<int> getDist(vector<vector<int>> tree, int src) {
  queue<int> q; 
  q.push(src);

  vector<int> dist(tree.size(), 0);
  vector<bool> vis(tree.size(), false); 
  
  vis[src] = true; 
  int level = 0; 

  while(q.size()) {
    int sz = q.size(); 
    while(sz--) {
      int top = q.front(); 
      q.pop(); 
      dist[top] = level;

      for(int nbr : tree[top]) {
        if(vis[nbr]) continue; 
        vis[nbr] = true; 
        q.push(nbr);
      }
    }
    ++level;
  }
  return dist; 
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

  int end_a, end_b;

  iter(tree, 1, 0, 0);
  mx_dist = 0; 
  end_a = node;
  iter(tree, node, 0, 0);
  end_b = node; 

  vector<int> from_a = getDist(tree, end_a); 
  vector<int> from_b = getDist(tree, end_b); 

  for(int i = 1; i <= n; ++i) {
    cout << max(from_a[i], from_b[i]) << ' '; 
  }

  return 0;
}