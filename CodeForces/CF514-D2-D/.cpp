// i use binary search on the length of the longest destroyed sequence, then i check this length from each position,
//and everytime to get the number of shots in a segment i use segment tree

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
int n,v,m,k;
int arr[200005][7];
int tree[900005][7];

void build(int node, int s, int e)
{
    if(s==e)
    {
        for(int i=1;i<=m;i++)
        tree[node][i]=arr[s][i];
        return ;
    }
    int mid=(s+e)/2;
    build(node*2,s,mid);
    build(node*2+1,mid+1,e);
    for(int j=1;j<=m;j++)
    tree[node][j]=max(tree[node*2][j],tree[node*2+1][j]) ;
}
int query(int node ,int s, int e ,int l ,int r,int i)
{
    if(s>e||s>r||e<l)return 0;
    if(s>=l&&e<=r)return tree[node][i];
    int mid=(s+e)/2;
    int q1=query(node*2,s,mid,l,r,i);
    int q2=query(node*2+1,mid+1,e,l,r,i);
    return max(q1,q2);
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    build(1,1,n);
    int s=1,e=n,mid;
    int idx=0,len=-1;
    while(s<=e)
    {
        mid=s+(e-s)/2;
        bool found=0;
        for(int i=1;i<=n;i++)
        {
            if(i+mid-1>=n+1)break;
            int sum=0;
            for(int j=1;j<=m;j++)
            {
                int u=query(1,1,n,i,i+mid-1,j);
                sum+=u;
            }
            if(sum<=k && mid>len)
                found=1,
                len=mid,
                idx=i;
        }
        if(found)s=mid+1;
        else e=mid-1;
    }
    if(len==-1){
    for(int i=0;i<m;i++)
        printf("0 ");
    return 0;
    }
    for(int i=1;i<=m;i++)printf("%d ", query(1,1,n,idx,idx+len-1,i));
    return 0;
}
