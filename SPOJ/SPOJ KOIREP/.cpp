//we save each value and the class it belongs to. then we sort, and using 2 pointers to try to find the smallest difference 
//between values, while making sure all the classes appear in this range

#include <bits/stdc++.h>
#include <bitset>
#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'
#define mod 1000000007
using namespace std;
 
 
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int> >v;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            {int a;cin>>a;v.push_back({a,i+1});}
    sort(v.begin(),v.end());
    int p1=0,p2=0,ans=1e9+10;
    int cnt[n+1];
    memset(cnt,0,sizeof cnt);
    cnt[v[0].second]++;
    int sofar=1;
    while(p1<n*m&&p2<n*m)
    {
        if(sofar==n){ans=min(ans,v[p2].first-v[p1].first);cnt[v[p1].second]--;if(!cnt[v[p1].second])sofar--; p1++;}
        else {p2++;if(p2==n*m)break;cnt[v[p2].second]++;if(cnt[v[p2].second]==1)sofar++;}
    }
    cout<<ans;
 
    return 0;
 
}
