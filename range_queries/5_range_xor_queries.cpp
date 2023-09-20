#include <bits/stdc++.h>
using namespace std;

class SegTree {
  vector<long long > ops; 
  int size; 

  public:
  void init(int n) {
    size = 1; 
    while(size < n) size = size * 2; 
    ops.assign(2*size, 0LL);
  }

  void build(vector<int> & a, int x, int lx, int rx) {
    if(rx - lx == 1) {
      if(lx < (int)a.size()) {
        ops[x] = a.at(lx); 
      }
      return;
    }

    int mid = (lx + rx) / 2;
    build(a,2 * x + 1, lx, mid);
    build(a, 2 * x + 2, mid , rx); 

    ops[x] = ops[2*x + 1] ^ ops[2*x+ 2];
  }

  void build(vector<int> & a) {
    build(a, 0, 0, size);
  }

  void build(int arr[], int n) {
    vector<int> a; 
    for(int i = 0; i < n; ++i) a.push_back(arr[i]);
    build(a);
  }

  void set(int i, int v, int x, int lx, int rx ){
    if(rx - lx == 1) {
      ops[x] = v;
      return;
    }

    int mid= (lx + rx)/2;

    if(i < mid) {
      set(i, v, 2 * x + 1, lx, mid); 
    } else {
      set(i, v, 2 * x + 2, mid, rx);
    }

    ops[x] = ops[2*x+1] ^ ops[2*x+2];
  }

  void set(int i, int v) {
    set(i, v, 0, 0, size);
  }

  long long sum(int l, int r, int x, int lx, int rx ){
    if(lx >= l and rx <= r) return ops[x];
    if(r <= lx or l >= rx) return 0LL; 
    
    int mid = (lx + rx)/2;

    return sum(l, r, 2 * x + 1, lx, mid) ^ sum(l, r, 2 * x + 2, mid, rx); 
  }

  long long sum(int l, int r) {
    return sum(l, r, 0, 0, size);
  }
};

int main() {
  int n, q;
  cin >> n >> q;
  int* arr = new int[n];
  for (int i = 0; i < n; ++i) cin >> arr[i];

  SegTree st; 
  st.init(n);
  st.build(arr, n); 

  while (q--) {
    int a, b; cin >> a >> b ; 
    cout << st.sum(a-1, b) <<endl;
  }

  return 0;
}
