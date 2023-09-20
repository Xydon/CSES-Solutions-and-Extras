#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<vector<int>> forest(n, vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char temp;
      cin >> temp;
      if (temp == '*') forest[i][j] = 1;
    }
  }

  vector<vector<int>> sum(n + 1, vector<int>(n + 1, 0));

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      sum[i][j] = sum[i][j - 1] + forest[i - 1][j - 1];
    }
  }
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      sum[i][j] += sum[i-1][j];
    }
  }

  for (int i = 0; i < q; ++i) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    cout << sum[c][d] - sum[c][b - 1] - sum[a - 1][d] +
                sum[a - 1][b - 1]
         << endl;
  }
}