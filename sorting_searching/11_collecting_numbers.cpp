#include <bits/stdc++.h>
using namespace std; 

int main() {
  int n; cin >> n; 
  vector<int> arr(n+1), pos(n+1), next(n+1, -1); 
  for(int i = 1; i <= n; ++i) {
    cin >> arr[i];
    pos[arr[i]] = i;
  }

  for(int i = 1; i <= n; ++i) {
    if(arr[i] != n){
      if(pos[arr[i] + 1] > i) {
        next[arr[i]] = pos[arr[i]+1];
      }
    }
  }

  int cnt =0 ;
  for(int i = 1; i <= n; ++i) {
    if(arr[i] == -1) continue; 
    int start = arr[i]; 
    arr[i] = -1; 
    while(next[start] != -1) {
      int prev = start;
      start = arr[next[start]];
      arr[next[prev]] = -1;
    }
    ++cnt;
  }

  cout << cnt << endl; 

  return 0; 
}