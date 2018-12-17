//i use segment tree, and for every shift, i update every position independently by the next value 
//and the last position is updated by the value in the first positon before the shift
//for every quert, the answer is just the minimum number in this segment 
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
ll n,arr[200005],v,m;
ll tree[900005];

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
    tree[node]=min(tree[node*2],tree[node*2+1]);
}
void update(int node,int s,int e ,int i)
{
    if(s==e){tree[node]=arr[i]=v;return ;}
    int mid=(s+e)/2;
    if(s<=i&&mid>=i)
    update(node*2,s,mid,i);
    else
    update(node*2+1,mid+1,e,i);
    tree[node]=min(tree[node*2],tree[node*2+1]);

}
int query(int node,int s,int e , int l,int r)
{
    if(e<l || s>r)return 1e9;
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
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&arr[i]);
    build(1,1,n);
    while(m--){
    char c;
    scanf("%c%c%c%c%c%c",&c,&c,&c,&c,&c,&c);
    if(c=='t'){
    char vv;
    scanf("%c",&vv);
    int last,aywa;
    scanf("%d",&last);
    scanf("%c",&vv);
    aywa=arr[last];
    int pre=last;
    while(1)
    {
        int cur;
        char s;
        scanf("%d%c",&cur,&s);
        v=arr[cur];
        update(1,1,n,pre);
        pre=cur;
        if(s==')')break;
    }
    v=aywa;
    update(1,1,n,pre);
    continue;
    }
    char cc,ccc,cccc;
    int nn,nnn;
    scanf("%c%d%c%d%c",&cc,&nn,&ccc,&nnn,&cccc);

    cout<<query(1,1,n,nn,nnn)<<endl;
    }
    return 0;
}
