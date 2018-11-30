#include <bits/stdc++.h>
//for every subject i enter all the skills, then i sort each subject skills in reverse order
//then i make accumulative sum
//and while doing that i calculate in arr[i] the best ans if we take i students , and then maximize at the end

#include <bitset>
#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'
#define mod 1000000007
using namespace std;

 ll arr[100001];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,m;
  cin>>n>>m;
  vector<vector<ll> > v(m);
  for(int i=0;i<n;i++)
  {
    int a,b;
    cin>>a>>b;
    a--;
    v[a].push_back(b);
  }
  for(int i=0;i<m;i++)
  {
    sort(v[i].rbegin(),v[i].rend());
  }
  for(int i=0;i<m;i++)
  {
    if(v[i].size())arr[0]+=(v[i][0]>0?v[i][0]:0);
    for(int j=1;j<v[i].size();j++)v[i][j]+=v[i][j-1],arr[j]+=(v[i][j]>0?v[i][j]:0);
  }
  ll ans=0;
  for(int i=0;i<100001;i++)ans=max(ans,arr[i]);
  cout<<ans;

  return 0;

}
