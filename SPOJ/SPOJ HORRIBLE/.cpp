//i use segment tree and lazy to update and answer the queries, each node is the sum of elements in this segment

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
ll n,arr[200005],v,m;
ll tree[900005];
ll lazy[900005];

void prop(int node,int s,int e)
{
    if(lazy[node])
    {
        tree[node]+=(e-s+1)*lazy[node];
        if(s!=e)
        lazy[node*2]+=lazy[node],
        lazy[node*2+1]+=lazy[node];
        lazy[node]=0;
    }
}

void update(int node,int s,int e ,int l , int r)
{
    prop(node,s,e);
    if(s>e || s>r || e<l)return;
    if(s>=l && e<=r)
    {
        tree[node]+=(e-s+1)*v;
        if(s!=e)
        lazy[node*2]+=v,
        lazy[node*2+1]+=v;
        return;
    }
    int mid=(s+e)/2;
    update(node*2,s,mid,l,r);
    update(node*2+1,mid+1,e,l,r);
    tree[node]=tree[node*2]+tree[node*2+1];

}
ll query(int node ,int s, int e ,int l ,int r)
{
    if(s>e||s>r||e<l)return 0;
    prop(node,s,e);
    if(s>=l&&e<=r)return tree[node];
    int mid=(s+e)/2;
    ll q1=query(node*2,s,mid,l,r),q2=query(node*2+1,mid+1,e,l,r);
    return q1+q2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    memset(tree,0,sizeof tree);
    memset(lazy,0,sizeof lazy);
    cin>>n>>m;
    while(m--)
    {
        int o,l,r;
        cin>>o>>l>>r;
        if(!o)cin>>v,update(1,1,n,l,r);
        else cout<<query(1,1,n,l,r)<<endl;
    }
    }
    return 0;
}
