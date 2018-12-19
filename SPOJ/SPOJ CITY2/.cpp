/*
      i save the positions of each height in a map
      then i iterate over them , and for every 2 consecutive positions 
      i get the minimum value in the segment between them from the query.
      if the minimum value is the current height itself, then this is still the same building
      otherwise this is a new building so we increase the number of buildings
*/

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
 
using namespace std;
ll n,arr[200005];
ll tree[900005];
map<int,vector<int> > v;
 
void build(int node, int s,int e )
{
    if(s==e)
    {
        tree[node]=arr[s];
        return ;
    }
    int mid=(s+e)/2;
    build(node*2,s,mid);
    build(node*2+1,mid+1,e);
    tree[node]=min(tree[node*2],tree[node*2+1]);
}
int query(int node,int s,int e , int l,int r)
{
    if(e<l || s>r)return 1e9+5;
    if(s>=l && e<=r){
    return tree[node];
    }
    int mid=(s+e)/2;
    int q1=query(node*2,s,mid,l,r);
    int q2=query(node*2+1,mid+1,e,l,r);
    return min(q1,q2);
}
 
int main()
{
    int casee=1;
    while(cin>>n){
    memset(tree,0,sizeof tree);
    memset(arr,0,sizeof arr);
    v.clear();
    for(int i=1;i<=n;i++)
        cin>>arr[i],
        v[arr[i]].push_back(i);
    build(1,1,n);
    int ans=0;
    for(map<int,vector<int> >::iterator it=v.begin();it!=v.end();it++)
    {
        if(it->first==0)continue;
        ans++;
        for(int j=1;j<it->second.size(); j++)
        {
            if(query(1,1,n,it->second[j-1],it->second[j])==it->first)continue;
            ans++;
        }
    }
    cout<<"Case "<<casee<<": "<<ans<<endl;
    casee++;
    }
    return 0;
}
