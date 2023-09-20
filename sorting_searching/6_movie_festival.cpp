#include <bits/stdc++.h>
using namespace std; 

int main() {
  int n; cin >> n;
  vector<pair<int, int>> vp(n); 
  
  for(int i =0 ; i < n; ++i) {
    cin >> vp[i].first >> vp[i].second;
  }

  sort(vp.begin(), vp.end());

  int ans = 0, end = 0;
  for(int i = 0; i < n; ++i) {
    if(i == 0){ 
      ans++;
      end = vp[i].second;
    } else {
      if(vp[i].first >= end) {
        end = vp[i].second;
        ans++;
      } else {
        end = min(end, vp[i].second);
      }
    }
  }

  cout << ans << endl; 

  return 0; 
}