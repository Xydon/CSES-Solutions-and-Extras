#include <bits/stdc++.h>
using namespace std; 

#define ll long long

int main() {
  int n; cin >> n; 
  vector<int> arr(n);
  for(int i =0 ; i < n; ++i) cin >> arr[i]; 

  ll csum = (ll)arr[0], gmax = (ll) arr[0]; 
  for(int i =1 ; i < n; ++i){ 
    if(csum + arr[i] < arr[i]) {
      csum = arr[i];
    } else {
      csum += arr[i];
    }
    gmax = max(csum, gmax);
  }

  cout << gmax << endl; 

  return 0; 
}