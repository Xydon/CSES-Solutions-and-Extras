#include <bits/stdc++.h>
using namespace std; 

int solve(vector<int> applicants, vector<int> apartments, int n, int m, int k) {
  multiset<int> ms; 
  for(auto i : applicants) ms.insert(i); 
  sort(apartments.begin(), apartments.end());

  int cnt = 0; 
  int i =0 , j = 0; 
  for(int i =0; i < m; ++i) {
    int sz = apartments[i]; 
    auto start = ms.lower_bound(sz-k);
    if(start != ms.end() and *start <= sz+k) {
      ms.erase(start);
      ++cnt;
    }
  }

  return cnt; 
}

int main() {
  int n; cin >> n; 
  int m; cin >> m; 
  int k; cin >> k; 
  
  vector<int> applicants(n); 
  for(int i =0 ; i < n; ++i) cin >> applicants.at(i); 
  vector<int> apartments(m); 
  for(int i = 0; i < m; ++i) cin >> apartments.at(i); 

  cout << solve(applicants, apartments, n, m, k) << endl; 
}