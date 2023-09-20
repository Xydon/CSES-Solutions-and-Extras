#include <bits/stdc++.h>
using namespace std; 

int main() {
  int n, q; cin >> n >> q; 

  long long * arr = new long long [n];

  for(int i = 0; i < n; ++i) {
    if(i == 0) cin >> arr[i];
    else {
      cin >> arr[i]; 
      arr[i] += arr[i-1];
    }
  }

  while(q--) {
    int a, b; cin >> a >> b;
    a--, b--; 
    if(a == 0) cout << arr[b] << endl; 
    else cout << arr[b] - arr[a-1] << endl ;
  }

  return 0;
}