#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n; 
  vector<pair<int, int>> vp;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    vp.push_back({a, 5});
    vp.push_back({b, 10});  
  }
  sort(vp.begin(), vp.end());
  int ans = 0;
  int globans = 0;
  for (int i = 0; i < vp.size(); i++) {
    if (vp[i].second == 5)
      ++ans;
    else
      --ans;
    globans = max(globans, ans);
  }
  cout << globans << endl;
}