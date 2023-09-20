#include <bits/stdc++.h>

#include <numeric>
#define ll long long
using namespace std;

ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

class Stack {
  vector<ll> s, smin = {LLONG_MAX}, smax = {LLONG_MIN}, sgcd = {0};

 public:
  void push(ll x) {
    s.push_back(x);
    ll mn = smin.back();
    ll mx = smax.back();
    smin.push_back(std::min(mn, x));
    smax.push_back(std::max(mx, x));

    sgcd.push_back(gcd(sgcd.back(), x));
  }

  ll pop() {
    ll res = s.back();
    s.pop_back();
    smin.pop_back();
    smax.pop_back();
    sgcd.pop_back();
    return res;
  }

  bool empty() { return s.empty(); }

  ll min() { return smin.back(); }

  ll max() { return smax.back(); }

  ll _gcd() {
      return sgcd.back();
  }
};

Stack s1, s2;

void add(ll x) { s2.push(x); }

void remove() {
  if (s1.empty()) {
    while (!s2.empty()) {
      s1.push(s2.pop());
    }
  }
  s1.pop();
}

bool good() {
  ll s1gcd = s1._gcd(), s2gcd = s2._gcd();

  return gcd(s1gcd, s2gcd) == 1;
}

int main() {
  int n;
  cin >> n;
  vector<ll> arr(n);

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  int l = 0;
  ll res = n + 1;
  for (int r = 0; r < n; ++r) {
    add(arr[r]);

    while (good()) {
      res = min(res, (ll)(r - l + 1));
      remove();
      l++;
    }
  }

  cout << (res == n+1 ? -1 : res) << endl;

  return 0;
}

void solve(vector<int> starts, int dist) {
  
}
