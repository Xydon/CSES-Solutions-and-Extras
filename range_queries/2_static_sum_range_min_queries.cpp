#include <bits/stdc++.h>
using namespace std;

class SQRTDecomposition {
  int n, sqrt_n;
  vector<int> arr, block;
  public:

  void init(vector<int> arr) {
    this->arr = arr;
    n = arr.size(); 
    sqrt_n = sqrt(n); 

    //* write function for processing 
    int temp = INT_MAX; 
    for(int i = 0; i < n; ++i){ 
      temp = min(temp, arr[i]);
      if((i+1)%sqrt_n == 0) {
        block.push_back(temp); 
        temp = INT_MAX; 
      }
    }
    if(temp != INT_MAX) {
      block.push_back(temp);
    }
  }

  void init (int arr[], int n) {
    for(int i = 0; i < n; ++i) {
      this->arr.push_back(arr[i]);
    }
    init(this->arr);
  }

  int get(int l, int r) {
    int ans = INT_MAX;
    while(l <= r) {
      if(l%sqrt_n == 0 and l -1 + sqrt_n <= r) {
        ans = min(ans, block.at(l/sqrt_n));
        l += sqrt_n;
      } else {
        ans = min(ans, arr[l]);
        l++;
      }
    }
    return ans; 
  }

  void update(int i, int v) {

  }
};

int main() {
  int n, q; cin >> n >> q; 
  int * arr= new int[n];
  for(int i = 0;  i < n; ++i) cin >> arr[i]; 
  SQRTDecomposition sd;
  sd.init(arr, n);

  while(q--) {
    int a,b; cin >> a >> b;
    a--, b--;
    cout << sd.get(a, b) << endl; 
  }

  return 0;
}