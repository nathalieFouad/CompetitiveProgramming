//basic segment tree to store the sum of the elements in each segment, and we update and do queries.

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
    tree[node]=tree[node*2]+tree[node*2+1];
}
void update(int node,int s,int e ,int i)
{
    if(s==e){tree[node]=arr[i]=v;return ;}
    int mid=(s+e)/2;
    if(s<=i&&mid>=i)
    update(node*2,s,mid,i);
    else
    update(node*2+1,mid+1,e,i);
    tree[node]=tree[node*2]+tree[node*2+1];

}
int query(int node,int s,int e , int l,int r)
{
    if(e<l || s>r)return 0;
    if(s>=l && e<=r){
    return tree[node];
    }
    int mid=(s+e)/2;
    int q1=query(node*2,s,mid,l,r),q2=query(node*2+1,mid+1,e,l,r);
    return q1+q2;
}

int main()
{
    int casee=1;
    bool b=0;
    while(cin>>n){
    if(!n)break;
    if(b)cout<<endl; 
    b=1;
    memset(tree,0,sizeof tree);
    memset(arr,0,sizeof arr);
    for(int i=1;i<=n;i++)cin>>arr[i];
    cout<<"Case "<<casee<<':'<<endl;
    casee++;
    build(1,1,n);
    while(1)
    {
        string s;
        cin>>s;
        if(s=="END")break;
        int l,r;
        cin>>l>>r;
        if(s=="M")cout<<query(1,1,n,l,r)<<endl;
        else v=r,update(1,1,n,l);
    }
    }
    return 0;
}
