#include <bits/stdc++.h>
using namespace std; 

int main() {
  int n, m; cin >> n >> m; 
  int * arr = new int[n]; 
  int * brr = new int [m]; 
  for(int i = 0; i < n; ++i) cin >> arr[i]; 
  for(int i = 0; i < m; ++i) cin >> brr[i]; 

  int i = 0, j = 0; 
  while(i < n or j < m) {
    if(j == m or i < n and arr[i] < brr[j]) {
      cout << arr[i++] << ' ';
    } else {
      cout << brr[j++] << ' ';
    }
  }

  return 0; 
}
