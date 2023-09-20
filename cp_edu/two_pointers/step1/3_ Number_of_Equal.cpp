#include<bits/stdc++.h>
using namespace std; 

int main() {
  int n, m; cin >> n >> m; 
  int * arr = new int[n];
  for(int i =0 ; i < n; ++i) cin >> arr[i];
  int * brr = new int[m];
  for(int i=0; i < m; ++i) cin >> brr[i]; 

  int i =0 , j = 0; 
  long long total = 0; 
  while(j < m) {
    long long c1 = 0, c2 = 0; 
    
    int curr = brr[j]; 
    while(j < m and brr[j] == curr) {
      ++c2; ++j;
    }

    while(i < n and arr[i] <= curr) {
      if(arr[i] == curr) ++c1; ++i; 
    }

    total += c1 * c2; 
  }

  cout << total << endl; 

  return 0; 
}
