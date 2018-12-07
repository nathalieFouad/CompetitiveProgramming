//we know that the first and the last element , one of them will not be removed, so we're sure that 
//one of the prime factors of the first number or the last is the final gcd of the array(we also consider the first number +1,
// and -1 , and the last element +1 or -1 , in case an operation of type 2 will be performed on them
//we have all the possible gcds in the set pp , so we try each one of them , whenever an element is not divisible by the cur 
//gcd , we know that we will either remove it within the segment, or increase it by 1 or decrease it by 1
//so we use dp to calculate the minimum possible answer
#include <bits/stdc++.h>
#include <bitset>
#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'
#define mod 1000000007
using namespace std;
set<ll>pp;
vector<ll>v(1e6+6);
ll n,a,b;

void primef(ll n)
{
    for(int i=2; i*i<=n; i++)
    {
            while (n%i==0)pp.insert(i),n/=i;
    }
    if(n>1)pp.insert(n);
}
ll solve(ll curp)
{
    ll dp[n+1][3];
    for(int i=0;i<n+1;i++)for(int j=0;j<3;j++)dp[i][j]=1e17;
    dp[0][0]=dp[0][1]=dp[0][2]=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<3;j++)
        {
            if((v[i]%curp)==0){dp[i][j]=dp[i-1][j]+(j==1?a:0);if(j==1)dp[i][j]=min(dp[i][j],dp[i-1][2]);}
            else{
            if((v[i]+1)%curp!=0 && (v[i]-1)%curp!=0 && j==2)continue;
            if(j==2)dp[i][j]=dp[i-1][j]+b;
            else if((v[i]+1)%curp!=0 && (v[i]-1)%curp!=0)dp[i][j]=dp[i-1][1]+a;
            else dp[i][j]=min(dp[i-1][j]+b+(j==1?a:0),dp[i-1][1]+a);
            }
        }
        return dp[n][0];
}


int main()
{
    ll ans=1e17;
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)cin>>v[i];
    primef(v[1]);primef(v[1]+1);primef(v[1]-1);primef(v[n]);primef(v[n]+1);primef(v[n]-1);
    for(set<ll>::iterator it=pp.begin();it!=pp.end();it++)
        ans=min(ans,solve(*it));
    cout<<ans;
    return 0;

}
