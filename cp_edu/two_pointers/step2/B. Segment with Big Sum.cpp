#include <bits/stdc++.h>
using namespace std; 

int main() {
  int n;
  long long s; 
  cin >> n >> s; 
  vector<int> arr(n);
  for(int i = 0; i < n; ++i) cin >> arr[i]; 

  long long temp = 0; 
  int j =0 ;
  int mx = INT_MAX;  
  for(int i =0 ; i < n; ++i){ 
    temp += arr[i]; 
    while(temp >= s) {
      mx = min(mx, i - j + 1);
      temp -= arr[j];
      j++;
    }
  }

  cout << (mx == INT_MAX ? -1 : mx) << endl; 

  return 0; 
}