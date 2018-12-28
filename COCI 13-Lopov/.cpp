/*
    we use a greedy algorithm , we sort the pieces according to their values from greater to smaller, then according 
    to their mass from smaller to greater.
    we iterate over the jewellery, and for the current piece we choose the smallest bag that can hold it, and we remove
    this bag, and add the value of this piece to the ans.
    if all the bags are smaller than the mass of the current piece, we go to the next piece.
    we keep doing this until k pieces are taken, or until we reach the end of the array.
*/

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

bool s(pair<ll,ll> a, pair<ll,ll> b)
{
    if(a.first>b.first)return 1;
    if(a.first==b.first && a.second<b.second)return 1;
    return 0;
}


int main()
{
    ll n,k;
    cin>>n>>k;
    pair<ll,ll> v[n];
    multiset<ll>bags;
    for(int i=0;i<n;i++)
        cin>>v[i].second>>v[i].first;
    for(int i=0;i<k;i++)
    {
        ll u;
        cin>>u;
        bags.insert(u);
    }
    sort(v,v+n,s);
    int co=0,i=0;
    ll ans=0;
    while(1)
    {
        if(co==k || i==n)
            break;
        set<ll>::iterator it=bags.lower_bound(v[i].second);
        if(it==bags.end())
            goto go;
        co++;
        bags.erase(it);
        ans+=v[i].first;
        go:;
        i++;
    }
    cout<<ans;
    return 0;
}
