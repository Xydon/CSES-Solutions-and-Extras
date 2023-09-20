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
  int mx = 0;  
  for(int i =0 ; i < n; ++i){ 
    temp += arr[i]; 
    
    while(temp > s) {
      temp -= arr[j];
      j++;
    }

    mx = max(mx, i-j +1);
  }

  cout << mx << endl; 

  return 0; 
}