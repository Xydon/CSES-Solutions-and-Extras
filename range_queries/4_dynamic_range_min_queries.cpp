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
    for (int i = 0; i < n; ++i) {
      temp = min(temp, arr[i]);
      if ((i + 1) % sqrt_n == 0) {
        block.push_back(temp);
        temp = INT_MAX;
      }
    }
    if (temp != INT_MAX) {
      block.push_back(temp);
    }
  }

  void init(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
      this->arr.push_back(arr[i]);
    }
    init(this->arr);
  }

  int get(int l, int r) {
    int ans = INT_MAX;
    while (l <= r) {
      if (l % sqrt_n == 0 and l - 1 + sqrt_n <= r) {
        ans = min(ans, block.at(l / sqrt_n));
        l += sqrt_n;
      } else {
        ans = min(ans, arr[l]);
        l++;
      }
    }
    return ans;
  }

  void update(int i, int v) {
    arr[i] = v;
    int start = (i/sqrt_n)* sqrt_n;
    int mn= INT_MAX;
    for(int k = start; k < min((int)arr.size(), start + sqrt_n); ++k) {
      mn = min(mn, arr[k]);
    }

    block.at(i/sqrt_n) = mn;
  }
};

class SegTree {
  vector<int> ops;
  int size;

 public:
  void init(int n) {
    size = 1;
    while (size < n) size = size * 2;
    ops.assign(2 * size, INT_MAX);
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

    ops[x] = min(ops[2 * x + 1], ops[2 * x + 2]);
  }

  void build(vector<int>& a) { build(a, 0, 0, size); }

  void build(int arr[], int n) {
    vector<int> a;
    for (int i = 0; i < n; ++i) a.push_back(arr[i]);
    build(a);
  }

  void set(int i, int v, int x, int lx, int rx) {
    if (rx - lx == 1) {
      ops[x] = v;
      return;
    }

    int mid = (lx + rx) / 2;

    if (i < mid) {
      set(i, v, 2 * x + 1, lx, mid);
    } else {
      set(i, v, 2 * x + 2, mid, rx);
    }

    ops[x] = min(ops[2 * x + 1], ops[2 * x + 2]);
  }

  void set(int i, int v) { set(i, v, 0, 0, size); }

  long long sum(int l, int r, int x, int lx, int rx) {
    if (lx >= l and rx <= r) return ops[x];
    if (r <= lx or l >= rx) return INT_MAX;

    int mid = (lx + rx) / 2;

    return min(sum(l, r, 2 * x + 1, lx, mid), sum(l, r, 2 * x + 2, mid, rx));
  }

  long long sum(int l, int r) { return sum(l, r, 0, 0, size); }
};

int main() {
  int n, q;
  cin >> n >> q;
  int* arr = new int[n];
  for (int i = 0; i < n; ++i) cin >> arr[i];
  SQRTDecomposition sd;
  sd.init(arr, n);

  while (q--) {
    int t, a, b;
    cin >> t >> a >> b;
    if (t == 1) {
      sd.update(a-1, b);
    } else {
      cout << sd.get(a-1, b-1) << endl; 
    }
  }

  return 0;
}
