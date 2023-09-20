#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n; 
  long long int * arr = new long long int[n];
  for(int i =0 ; i < n; ++i) {
    cin >> arr[i]; 
  }

  sort(arr,arr+n);

  long long targ = 1;
  for(int i =0 ;i < n; ++i) {
    if(arr[i] > targ) break;
    targ += arr[i]; 
  }
  cout << targ << endl; 

  return 0; 
}