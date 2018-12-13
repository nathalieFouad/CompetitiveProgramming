//we need to know the gcd for each segment given in the queries, so we build a segment tree
/where each node is the gcd of this segment , 
//and for each query, we get the gcd , and then see how many times this gcd appears in the range using binary search over
//a map that stores all the positions of a number
//then in order to know how many ants will be eaten , we simply have to subtract the number of occurences of this gcd
//from the total number of ants in the range.

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
int n,arr[100005];
int tree[900005];
map<int,vector<int> > mp;

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
    tree[node]=__gcd(tree[node*2],tree[node*2+1]);

}
int query(int node, int s, int e , int l ,int r)
{
    if(s>r || e<l)return -1;
    if(s>=l && e<=r)return tree[node];
    int mid=(s+e)/2;
    int q1=query(node*2,s,mid,l,r),q2=query(node*2+1,mid+1,e,l,r);
    if(q1==-1)return q2;
    if(q2==-1)return q1;
    return __gcd(q1,q2);
}



int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i],mp[arr[i]].push_back(i);
    build(1,1,n);
    int m;
    cin>>m;
    while(m--)
    {
        int l, r;
        cin>>l>>r;
        int gcd=query(1,1,n,l,r);
        int pos=lower_bound(mp[gcd].begin(),mp[gcd].end(),l)-mp[gcd].begin();
        int pos2=upper_bound(mp[gcd].begin(),mp[gcd].end(),r)-mp[gcd].begin();
        if(pos>=mp[gcd].size()){cout<<r-l+1<<endl;continue;}
        pos2--;
        if(mp[gcd][pos]>r){cout<<r-l+1<<endl;continue;}
        if(pos2<pos){cout<<r-l+1<<endl;continue;}
        if(pos2==pos && mp[gcd][pos]>=l && mp[gcd][pos]<=r){cout<<r-l<<endl;continue;}
        cout<<r-l+1-(pos2-pos+1)<<endl;
    }
    return 0;
}
