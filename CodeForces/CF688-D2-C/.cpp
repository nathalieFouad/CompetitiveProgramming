/*
        the idea is that all the nodes of the odd levels will be in the first set, and the nodes of the even levels will
        be in the second set.
        dfs and insert the nodes in the sets.
        if after finishing, i find that the 2 nodes of an edge are in the same set, this means that there is no solution,
        because that means that they're both have the same parity of levels, but we know for sure that's not the case since
        they are 2 connected nodes, so one of them must have an even level, and the other odd.
*/

#include <bits/stdc++.h>
#include <bitset>
#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'
#define mod 998244353
using namespace std;

vector<vector<int> > v;
bool visited[100005],z[100005];
set<int>se,se2;

void dfs(int node,bool first)
{
    if(visited[node])return;
    visited[node]=1;
    if(first)se.insert(node);
    else se2.insert(node);
    for(int i=0;i<v[node].size();i++)
        dfs(v[node][i],!first);
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int> > edges;
    v.resize(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        z[a]=z[b]=1;
        v[a].push_back(b);
        v[b].push_back(a);
        edges.push_back({a,b});
    }
    for(int i=1;i<=n;i++)
    if(!visited[i] && z[i])
    dfs(i,1);
    for(int k=0;k<m;k++)
    {
        int a=edges[k].first,b=edges[k].second;
        set<int>::iterator it=se.lower_bound(a);
        set<int>::iterator it2=se.lower_bound(b);
        set<int>::iterator i=se2.lower_bound(a);
        set<int>::iterator i2=se2.lower_bound(b);
        if((it!=se.end() && *it==a&&it2!=se.end()&& *it2==b)||(i!=se2.end()&&*i==a&&i2!=se2.end()&&*i2==b) )
          return cout<<-1,0;
    }
    cout<<se.size()<<endl;
    for(set<int>::iterator it=se.begin();it!=se.end();it++)cout<<*it<<' ' ;
    cout<<endl<<se2.size()<<endl;
    for(set<int>::iterator it=se2.begin();it!=se2.end();it++)cout<<*it<<' ' ;
    return 0;
}
