#include <bits/stdc++.h>
using namespace std; 

#define ll long long 

long long f(vector<int> arr, int tar) {
  long long diff_sum =0; 
  for(int i =0 ; i < (int)arr.size(); ++i) {
    diff_sum += (long long) abs(arr[i] - tar);
  }
  return diff_sum;
}

int main() {
  int n; cin >> n; 
  vector<int> arr(n); 
  for(int i = 0; i < n; ++i) cin >> arr[i]; 

  ll l = 0, r = 1;
  int mx = *max_element(arr.begin(), arr.end());
  while(r <= (ll)mx) {
    r = r*2;
  }

  ll ans = 0;

  while(l <= r) {
    ll mid = (l+r)/2;
    ll curr = f(arr, mid);
    ll next = f(arr, mid+1);
    ans = min(curr, next);
    if(next < curr) {
      l = mid+1;
    } else {
      r = mid-1;
    }
  }

  cout << ans << endl ;

  return 0;
}