#include <bits/stdc++.h>
using namespace std; 

class SegTree {
  vector<int> ops;
  int size;

 public:
  void init(int n) {
    size = 1;
    while (size < n) size = size * 2;
    ops.assign(2 * size, INT_MIN);
  }

  void build(vector<int>& a, int x, int lx, int rx) {
    if (rx - lx == 1) {
      if (lx < (int)a.size()) {
        ops[x] = a.at(lx);
      }
      return;
    }

    int mid = (lx + rx) / 2;
    build(a, 2 * x + 1, lx, mid);
    build(a, 2 * x + 2, mid, rx);

    ops[x] = max(ops[2 * x + 1], ops[2 * x + 2]);
  }

  void build(vector<int>& a) { build(a, 0, 0, size); }

  void build(int arr[], int n) {
    vector<int> a;
    for (int i = 0; i < n; ++i) a.push_back(arr[i]);
    build(a);
  }

  void set(int i, int v, int x, int lx, int rx) {
    if (rx - lx == 1) {
      ops[x] -= v;
      return;
    }

    int mid = (lx + rx) / 2;

    if (i < mid) {
      set(i, v, 2 * x + 1, lx, mid);
    } else {
      set(i, v, 2 * x + 2, mid, rx);
    }

    ops[x] = max(ops[2 * x + 1], ops[2 * x + 2]);
  }

  void set(int i, int v) { set(i, v, 0, 0, size); }

  long long sum(int l, int r, int x, int lx, int rx) {
    if (lx >= l and rx <= r) return ops[x];
    if (r <= lx or l >= rx) return INT_MIN;

    int mid = (lx + rx) / 2;

    return max(sum(l, r, 2 * x + 1, lx, mid), sum(l, r, 2 * x + 2, mid, rx));
  }

  long long sum(int l, int r) { return sum(l, r, 0, 0, size); }
};


int main() {

  int n, m; cin >> n >> m;
  vector<int> hotels(n, 0); 
  for(int i= 0; i < n; ++i) cin >> hotels[i];

  SegTree st; 
  st.init(n);
  st.build(hotels);

  for(int i = 0; i < m; ++i){ 
    int val; cin >> val; 

    int start = 0, end = n, last = -1;
    while(start <= end) {
      int mid = (start+end)/2;
      if(st.sum(0, mid+1) < val) {
        start = mid+1;
      } else {
        last = mid;
        end = mid - 1;
      }
    }

    if(last == -1) cout << 0 << ' '; 
    else cout << last+1 << ' '; 

    if(last != -1) st.set(last, val);
  }

  return 0; 
}