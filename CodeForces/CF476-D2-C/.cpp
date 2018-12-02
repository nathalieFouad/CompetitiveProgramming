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

    ll a,b,ans=0;
    cin>>a>>b;
    for(ll i=1;i<=a;i++)
    {
        ans+= ( ((i*b+1)%mod ) * ( (b*(b-1)/2)%mod  ) ) %mod;
        ans%=mod;
    }
    cout<<ans;
    return 0;

}
