#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> par;
vector<int> depth;

void iter(vector<vector<int>> & tree, int src, int par, int d) {
  depth[src] = d; 
  for(int nbr : tree[src]) {
    if(nbr != par) {
      iter(tree, nbr, src, d+1);
    }
  }
}

int getKth(int a, int b) {
  for (int i = 0; i <= 19; ++i) {
    int mask = 1 << i;
    if (b & mask) {
      a = par[a][i];
      if (a == -1) break;
    }
  }
  return a;
}

int getLca(int a, int b) {
  if(depth[a] < depth[b]) {
    swap(a, b); 
  }

  int k = depth[a] - depth[b]; 
  for(int j = 20 - 1; j >= 0; j--) {
		if(k & (1 << j)) {
			a = par[a][j]; // parent of a
		}
	}

  if(a ==b) return a; 

  for(int j = 20 - 1; j >= 0; j--) {
		if(par[a][j] != par[b][j]) {
			a = par[a][j];
			b = par[b][j];
		}
	}

  return par[a][0];
}

int main() {
  int q;
  cin >> n >> q;
  par = vector<vector<int>>(n + 1, vector<int>(20, 1));
  depth = vector<int>(n+1, 0);
  

  vector<vector<int>> tree(n+1);

  // kth pre-processing
  for (int i = 2; i <= n; ++i) {
    cin >> par[i][0];
    tree[i].push_back(par[i][0]);
    tree[par[i][0]].push_back(i);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 19; ++j) {
      par[i][j] = (par[i][j - 1] == -1) ? -1 : par[par[i][j - 1]][j - 1];
    }
  }

  // depth pre-processing
  iter(tree, 1, 0, 0);

  // for(int i=1;i <=n; ++i) cout <<depth[i] << ' ';

  for(int i = 0; i < q; ++i) {
    int a, b; cin >> a >> b; 
    cout << getLca(a, b) << endl; 
  }

  return 0; 
}