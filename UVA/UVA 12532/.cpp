//we use basic segment tree, we update and we get the sign of the given range in the query
//to prevent overflow we save +ve values as 1, -ve values as -1, and 0 as it is
//since we only need the signs

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
ll n,arr[200005],v;
ll tree[900005];

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
    tree[node]=tree[node*2]*tree[node*2+1];
}
void update(int node,int s,int e ,int i)
{
    if(s==e){tree[node]=arr[i]=v;return ;}
    int mid=(s+e)/2;
    if(s<=i&&mid>=i)
    update(node*2,s,mid,i);
    else
    update(node*2+1,mid+1,e,i);
    tree[node]=tree[node*2]*tree[node*2+1];

}
int query(int node,int s,int e , int l,int r)
{
    if(e<l || s>r)return -2;
    if(s>=l && e<=r){
    if(tree[node]>0)return 1;
    if(tree[node]==0)return 0;
    return -1;
    }
    int mid=(s+e)/2;
    int q1=query(node*2,s,mid,l,r),q2=query(node*2+1,mid+1,e,l,r);
    if(q1==-2)return q2;
    if(q2==-2)return q1;
    return q1*q2;
}

int main()
{
    while(cin>>n){
    memset(tree,0,sizeof tree);
    memset(arr,0,sizeof arr);
    int k;
    cin>>k;
    for(int i=1;i<=n;i++){cin>>arr[i];if(arr[i]<0)arr[i]=-1;else if(arr[i]>0)arr[i]=1;}
    build(1,1,n);
    while(k--)
    {
        char c;
        int l ,r;
        cin>>c>>l>>r;
        if(c=='C'){v=r;if(v<0)v=-1;if(v>0)v=1;update(1,1,n,l);}
        else {
        int ans=query(1,1,n,l,r);
        if(ans==0)cout<<0;
        else if(ans==-1)cout<<'-';
        else cout<<'+';
        }
    }
    cout<<endl;
    }
    return 0;
}
