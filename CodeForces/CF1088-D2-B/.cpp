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
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end());
    vector<int>ans;
    int sub=0;
    for(int i=0;i<n;i++)
    {
        if(!v[i])continue;
        if(v[i]>sub)ans.push_back(v[i]-sub);
        v[i]-=sub;
        sub+=v[i];
    }
    int c=0;
    for(int i=0;i<min((int)ans.size(),k);i++){c++;cout<<ans[i]<<endl;}
    if(c<k)for(int i=0;i<k-c;i++)cout<<0<<endl;
    return 0;

}
