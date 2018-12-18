// i use segment tree and lazy, whenever i need to update a node, if the operation is F or E we just set or clear all of 
//the segment and we mark the lazy of the children with the same operation, if the operation is invert,
//we invert the current segment, and for the children , if the lazy is already inverted, then we mark that no operations need
//to be done, if the lazy is F , we make it E, and vice versa, otherwise we mark that it will be inverted

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
ll n,arr[2000005],v,m;
ll tree[9000005];
ll lazy[9000005];

void build(int node, int s, int e)
{
    if(s==e)
    {
        tree[node]=arr[s];
        return ;
    }
    int mid=(s+e)/2;
    build(node*2,s,mid);
    build(node*2+1,mid+1,e);
    tree[node]=tree[node*2]+tree[node*2+1];
}
void prop(int node,int s,int e)
{
    if(lazy[node]==-1)return ;
    if(lazy[node]==1)
    {
        tree[node]=(e-s+1);
        if(s!=e)
        lazy[node*2]=1,
        lazy[node*2+1]=1;
        lazy[node]=-1;
    }
    if(lazy[node]==2)
    {
        tree[node]=0;
        if(s!=e)
        lazy[node*2]=2,
        lazy[node*2+1]=2;
        lazy[node]=-1;
    }
    if(lazy[node]==3)
    {
        tree[node]=(e-s+1)-tree[node];
        if(s!=e)
        {
            if(lazy[node*2]==-1)lazy[node*2]=3;
            else if(lazy[node*2]==1)lazy[node*2]=2;
            else if(lazy[node*2]==2)lazy[node*2]=1;
            else lazy[node*2]=-1;

            if(lazy[node*2+1]==-1)lazy[node*2+1]=3;
            else if(lazy[node*2+1]==1)lazy[node*2+1]=2;
            else if(lazy[node*2+1]==2)lazy[node*2+1]=1;
            else lazy[node*2+1]=-1;
        }
        lazy[node]=-1;
    }
}

void update(int node,int s,int e ,int l , int r)
{
    prop(node,s,e);
    if(s>e || s>r || e<l)return;
    if(s>=l && e<=r)
    {
        if(v==1)tree[node]=(e-s+1);
        else if(v==2)tree[node]=0;
        else tree[node]=(e-s+1)-tree[node];
        if(s!=e)
        {
            if(v==1)lazy[node*2]=lazy[node*2+1]=1;
            else if(v==2)lazy[node*2+1]=lazy[node*2]=2;
            else{
            if(lazy[node*2]==-1)lazy[node*2]=3;
            else if(lazy[node*2]==1)lazy[node*2]=2;
            else if(lazy[node*2]==2)lazy[node*2]=1;
            else lazy[node*2]=-1;

            if(lazy[node*2+1]==-1)lazy[node*2+1]=3;
            else if(lazy[node*2+1]==1)lazy[node*2+1]=2;
            else if(lazy[node*2+1]==2)lazy[node*2+1]=1;
            else lazy[node*2+1]=-1;
                }
        }
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
    ll q1=query(node*2,s,mid,l,r);
    ll q2=query(node*2+1,mid+1,e,l,r);
    return q1+q2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin>>t;
    int casee=1;
    while(t--)
    {
        cout<<"Case "<<casee<<":"<<endl;
        casee++;
        memset(arr,0,sizeof arr);
        memset(tree,0,sizeof tree);
        memset(lazy,-1,sizeof lazy);
        n=0;
        int kam;
        cin>>kam;
        string s;
        while(kam--)
        {
            int times; string h;
            cin>>times>>h;
            n+=times*(int)h.size();
            while(times--)s+=h;
        }
        for(int i=1;i<=n;i++)arr[i]=(s[i-1]=='1'?1:0);
        build(1,1,n);
        cin>>m;
        int q=1;
        while(m--)
        {
            char c;
            int l,r;
            cin>>c>>l>>r;
            l++;
            r++;
            if(c=='F')
            v=1,
            update(1,1,n,l,r);
            else if(c=='E')
            v=2,
            update(1,1,n,l,r);
            else if(c=='I')
            v=3,
            update(1,1,n,l,r);
            else
            cout<<"Q"<<q<<": "<<query(1,1,n,l,r)<<endl,
            q++;
        }
    }
    return 0;
}
