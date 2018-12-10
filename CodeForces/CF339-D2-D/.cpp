//we build a segment tree, and we update for each query , if the level is 0 and n is even , then we do xor
//also if the level is 1 and n is odd, we xor
//otherwise we use or

#include <bits/stdc++.h>
#include <bitset>
#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'
#define mod 1000000007
using namespace std;

ll tree[400005];
ll arr[200005];
ll n,m,v;
bool N;

void build(int s , int e, int node,bool level)
{
    if(s==e)
    {
        tree[node]=arr[s];
        return ;
    }
    int mid=(s+e)/2;
    build(s,mid,node*2,level^1);
    build(mid+1,e,node*2+1,level^1);
    tree[node]=(level==N?tree[2*node]^tree[2*node+1]:tree[2*node]|tree[2*node+1]);
}
void update(int s, int e , int node, int i,bool level)
{
    if(s==e)
    {
        tree[node]=v;
        return ;
    }
    int mid=(s+e)/2;
    if(i>=s&&i<=mid)
    {
        update(s,mid,node*2,i,level^1);
    }
    else update(mid+1,e,node*2+1,i,level^1);
    tree[node]=(level==N?tree[2*node]^tree[2*node+1]:tree[2*node]|tree[2*node+1]);
}

int main()
{
    cin>>n>>m;
    N=n%2==1;
    ll sizee=pow(2,n);
    for(int i=1;i<=sizee;i++)cin>>arr[i];
    build(1,sizee,1,0);
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        v=b;
        update(1,sizee,1,a,0);
        cout<<tree[1]<<endl;
    }
    return 0;
}
