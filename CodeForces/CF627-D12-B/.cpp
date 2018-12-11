//we use 2 segment trees one to store the number of orders if the limit is a (treea) , and the other to store the number of 
//orders if the limit is b (treeb).
//for each query of type 1, we update the trees according to the limit of each one
//for each query of type 2, we know that from index -> index+k will not give us an answer , 
//and segment 1 -> index-1 will give us the answer but with limit b , so we get it from treeb
//also segment index+k -> N will give us hte answer with limit a , so we get it from treea

#include <bits/stdc++.h>
#include <bitset>
#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'
#define mod 1000000007
using namespace std;

ll treea[900005];
ll treeb[900005];
ll arr[200005];
ll n,k,a,b,q,o;
bool A;

void updateb(int s,int e ,int node,int i)
{
    if(s==e)
    {
        treeb[node]=min(treeb[node]+o,b);
        return ;
    }
    int mid=(s+e)/2;
    if(i>=s&&i<=mid)
    {
        updateb(s,mid,node*2,i);
    }
    else updateb(mid+1,e,node*2+1,i);
    treeb[node]=treeb[2*node]+treeb[2*node+1];
}

void updatea(int s, int e , int node, int i)
{
    if(s==e)
    {
        treea[node]=min(treea[node]+o,a);
        return ;
    }
    int mid=(s+e)/2;
    if(i>=s&&i<=mid)
    {
        updatea(s,mid,node*2,i);
    }
    else updatea(mid+1,e,node*2+1,i);
    treea[node]=treea[2*node]+treea[2*node+1];
}
ll query(int s,int e, int node,int r, int l )
{
    if(s>r || e<l)return 0;
    if(s>=l && e<=r)return (A?treea[node]:treeb[node]);
    int mid=(s+e)/2;
    ll q1=query(s,mid,node*2,r,l),q2=query(mid+1,e,node*2+1,r,l);
    return q1+q2;
}


int main()
{
    cin>>n>>k>>a>>b>>q;
    memset(treea,0,sizeof treea);
    memset(treeb,0,sizeof treeb);
    while(q--)
    {
        int x;cin>>x;
        if(x==1){
        ll i;
        cin>>i>>o;
        updatea(1,n,1,i);
        updateb(1,n,1,i);
        }
        else
        {
            ll ans=0;
            ll i;
            cin>>i;
            A=0;
            if(i!=1)
            ans+=query(1,n,1,i-1,1);
            A=1;
            if(i+k<=n)
            ans+=query(1,n,1,n,i+k);
            cout<<ans<<endl;
        }
    }
    return 0;
}
