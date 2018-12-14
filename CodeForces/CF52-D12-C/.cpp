// we use lazy, for each query we update or we get the minimum in segment depending on the query,
//i handle the "circular part" , by getting the min in the segment if pos1<=pos2
//else i get the min in the segment from pos1->n and the min in the seg from 1->pos2, and we get the min between them

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
ll n,arr[200005],v;
ll tree[900005];
ll lazy[900005];

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
void update(int node,int s,int e ,int l , int r)
{
    if(lazy[node])
    {
        tree[node]+=lazy[node];
        if(s!=e)
        lazy[node*2]+=lazy[node],
        lazy[node*2+1]+=lazy[node];
        lazy[node]=0;
    }
    if(s>e || s>r || e<l)return;
    if(s>=l && e<=r)
    {
        tree[node]+=v;
        if(s!=e)
        lazy[node*2]+=v,
        lazy[node*2+1]+=v;
        return;
    }
    int mid=(s+e)/2;
    update(node*2,s,mid,l,r);
    update(node*2+1,mid+1,e,l,r);
    tree[node]=min(tree[node*2],tree[node*2+1]);

}
ll query(int node ,int s, int e ,int l ,int r)
{
    if(s>e||s>r||e<l)return 1e17;
    if(lazy[node])
    {
        tree[node]+=lazy[node];
        if(s!=e)
        lazy[node*2]+=lazy[node],
        lazy[node*2+1]+=lazy[node];
        lazy[node]=0;
    }
    if(s>=l&&e<=r)return tree[node];
    int mid=(s+e)/2;
    ll q1=query(node*2,s,mid,l,r),q2=query(node*2+1,mid+1,e,l,r);
    return min(q1,q2);
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    build(1,1,n);
    int m;
    cin>>m;
    cin.ignore();
    while(m--)
    {
        string a;
        getline(cin,a);
        int b=0, c=0;
        v=0;
        bool neg=0,sec=0,th=0,mawgood=0;
        for(int i=0;i<(int)a.size();i++)
        {
            if(a[i]==' '){if(!sec){sec=1;continue;} th=1;continue;}
            if(!sec && !th)b*=10,b+=a[i]-'0';
            else if(!th)c*=10,c+=a[i]-'0';
            else {mawgood=1;if(a[i]=='-'){neg=1;continue;}v*=10;v+=a[i]-'0';}
        }
        b++;
        c++;
        if(!mawgood){
        if(b<=c)
        cout<<query(1,1,n,b,c)<<endl;
        else cout<<min(query(1,1,n,b,n),query(1,1,n,1,c))<<endl;
        }
        else{
        if(neg)v*=-1;
        if(b<=c)update(1,1,n,b,c);
        else update(1,1,n,b,n),update(1,1,n,1,c);
        }
    }
    return 0;
}
