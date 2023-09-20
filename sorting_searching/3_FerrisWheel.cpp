#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main() {

  int n,x;
  cin>>n>>x;
  vector<int> ar(n);
  for(int i=0;i<n;i++) cin>>ar[i];

  sort(ar.begin() , ar.end());
  int l=0,r=n-1;
  int ans=0;
  while(l<=r)
  {
    if(ar[r]==x) 
    {
      ++ans;
      --r;
      continue;
    }
    if(ar[r]+ar[l]<=x)
    {
      ++ans;
      ++l;
      --r;
      continue;
    }

    ++ans;
    --r;



  }

  cout<<ans<<endl;



  
}