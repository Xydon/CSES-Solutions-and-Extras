#include <bits/stdc++.h>
using namespace std;

class SQRTDecomposition {
  int n, sqrt_n;
  vector<long long> arr, block;

 public:
  void init(vector<long long> arr) {
    this->arr = arr;
    n = arr.size();
    sqrt_n = sqrt(n);

    //* write function for processing
    long long temp = 0;
    for (int i = 0; i < n; ++i) {
      temp += arr[i];
      if ((i + 1) % sqrt_n == 0) {
        block.push_back(temp);
        temp = 0;
      }
    }
    if (temp != 0) {
      block.push_back(temp);
    }
  }

  void init(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
      this->arr.push_back(arr[i]);
    }
    init(this->arr);
  }

  long long get(int l, int r) {
    long long ans = 0;
    while (l <= r) {
      if (l % sqrt_n == 0 and l - 1 + sqrt_n <= r) {
        ans += (block.at(l / sqrt_n));
        l += sqrt_n;
      } else {
        ans += arr[l];
        l++;
      }
    }
    return ans;
  }

  void update(int i, int v) {
    int bno = i / sqrt_n;
    block.at(bno) = block.at(bno) - arr[i] + v;
    arr[i] = v;
  }
};

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

    ops[x] = ops[2*x + 1] + ops[2*x+ 2];
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

    ops[x] = ops[2*x+1] + ops[2*x+2];
  }

  void set(int i, int v) {
    set(i, v, 0, 0, size);
  }

  long long sum(int l, int r, int x, int lx, int rx ){
    if(lx >= l and rx <= r) return ops[x];
    if(r <= lx or l >= rx) return 0; 
    
    int mid = (lx + rx)/2;

    return sum(l, r, 2 * x + 1, lx, mid) + sum(l, r, 2 * x + 2, mid, rx); 
  }

  long long sum(int l, int r) {
    return sum(l, r, 0, 0, size);
  }
};

int main() {
  int n, q; cin >> n >> q; 
  int *arr = new int [n]; 

  for(int i = 0; i < n; ++i) cin >> arr[i]; 

  SQRTDecomposition sd; 
  SegTree st;
  
  st.init(n);
  st.build(arr, n);  

  while(q--) {
    int t, a, b; cin >> t >> a >> b; 
    if(t == 1) {
      a--;
      st.set(a, b); 
    } else {
      cout << st.sum(a-1, b) << endl; 
    }
  }

  return 0; 
}