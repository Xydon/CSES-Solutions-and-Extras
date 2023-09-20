#include <bits/stdc++.h> 
using namespace std; 

vector<int> dp; 

void iter(vector<vector<int>> & tree, int src, int par) {
	dp[src] = 0; 
	for(int nbr : tree[src]) {
		if(nbr != par) {
			iter(tree, nbr, src); 
			dp[src] += dp[nbr] + 1; 
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;cin >> n; 
	
	dp = vector<int>(n+1, 0); 
	
	vector<vector<int>> tree(n+1); 
	for(int i = 2 ; i <= n; ++i) {
		int inp; cin >> inp; 
		tree[inp].push_back(i); 
	}
	
	iter(tree, 1, -1);
	
	for(int i = 1; i <= n; ++i) {
		cout << dp[i] << ' ';
	}
	
	return 0; 
	
}
