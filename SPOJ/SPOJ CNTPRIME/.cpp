//i use segment tree and lazy to update and get the answers to the queries , for each number if it's prime, it's stored as 1
//else it's zero , and the segment tree calculates the sum of each range , so only primes are counted

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
ll n,arr[200005],v,m;
ll tree[900005];
ll lazy[900005];

bool check(int nn)
{
    if(nn==1 || nn==0)return 0;
    for(int i=2;i*i<=nn;i++)
            if(nn%i==0)return 0;
    return 1;
}

void build(int node, int s,int e )
{
    if(s==e)
    {
        tree[node]=check(arr[s]);
        return ;
    }
    int mid=(s+e)/2;
    build(node*2,s,mid);
    build(node*2+1,mid+1,e);
    tree[node]=tree[node*2]+tree[node*2+1];
}

void prop(int node,int s,int e)
{
    if(lazy[node]!=-1)
    {
        tree[node]=lazy[node]*(e-s+1);
        if(s!=e)
        lazy[node*2]=lazy[node],
        lazy[node*2+1]=lazy[node];
        lazy[node]=-1;
    }
}

void update(int node,int s,int e ,int l , int r)
{
    prop(node,s,e);
    if(s>e || s>r || e<l)return;
    if(s>=l && e<=r)
    {
        tree[node]=(e-s+1)*v;
        if(s!=e)
        lazy[node*2]=v,
        lazy[node*2+1]=v;
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
    for(int ca=1;ca<=t;ca++){
    cout<<"Case "<<ca<<':'<<endl;
    memset(arr,0,sizeof arr);
    memset(tree,0,sizeof tree);
    memset(lazy,-1,sizeof lazy);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>arr[i];
    build(1,1,n);
    while(m--)
    {
        int o,l,r;
        cin>>o>>l>>r;
        if(!o)cin>>v,v=check(v),update(1,1,n,l,r);
        else cout<<query(1,1,n,l,r)<<endl;
    }

    }
    return 0;
}
