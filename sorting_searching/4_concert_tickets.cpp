#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  multiset<int> ms;
  for (int i = 0; i < n; ++i) {
    int inp;
    cin >> inp;
    ms.insert(inp);
  }
  for (int i = 0; i < m; ++i) {
    int inp;
    cin >> inp;
    if (ms.find(inp) != ms.end()) {
      auto f = ms.find(inp);
      ms.erase(f);
      cout << inp << endl;
      continue;
    }
    if (ms.size() == 0) {
      cout << -1 << endl;
      continue;
    }

    
    auto ub = ms.upper_bound(inp);
    if (ub == ms.begin()) {
      cout << -1 << endl;
    } else {
      ub--;
      cout << (*ub) << endl;
      ms.erase(ub);
    }
  }

  return 0;
}