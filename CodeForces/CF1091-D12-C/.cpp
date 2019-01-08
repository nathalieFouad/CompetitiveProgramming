/*
      the number of distinct fun values, is the number of divisors of N.
      to calculate the fun value for each divisor:
      for ex if the cur=3 and N=12 , the fun value= 1+4+7+10
      = 1+ (1*3+1) + (2*3+1) + (3*3+1)
      = 1+ (1+2+3) * (3) + (1+1+1)
      the number of terms that have the cur are N/cur-1 = u
      uu= the sum from 1 to u
      so the the fun value for the cur = uu*cur + u + 1 ;
*/

#include <bits/stdc++.h>
#include <bitset>
#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'
#define mod 998244353
using namespace std;


int main()
{
   ll n;
   cin>>n;
   set<ll>se,f;
   for(ll i=1;i*i<=n;i++)
   {
        if(n%i==0)
        f.insert(i),
        f.insert(n/i);
   }
   for(set<ll>::iterator it=f.begin();it!=f.end();it++)
   {
        ll cur=*it;
        ll cnt=0;
        ll u=n/cur-1;
        ll uu=u*(u+1)/2;
        cnt=uu*cur;
        cnt+=u;
        cnt++;
        se.insert(cnt);
   }
   for(set<ll>::iterator it=se.begin();it!=se.end();it++)
    cout<<*it<<" ";
    return 0;
}
