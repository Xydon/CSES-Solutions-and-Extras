#include<bits/stdc++.h>
using namespace std; 

int main() {
  int n, m; cin >> n >> m; 
  int * arr = new int[n];
  for(int i =0 ; i < n; ++i) cin >> arr[i];
  int * brr = new int[m];
  for(int i=0; i < m; ++i) cin >> brr[i]; 

  int i =0 , j = 0; 
  while(j < m) {
    while(i < n and arr[i] < brr[j]) ++i;
    cout << i << ' ';
    ++j;
  }

  return 0; 
}