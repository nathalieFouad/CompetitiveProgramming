/*
      i get all the strongly connected components in the vector comp, and for each component we need to put a station in one
      of its nodes, so we get the minimum cost in the component and add it to the answer, and we get the freq of the mimimum 
      value in each component, and the number of ways to obtain the answer is the product of all the frequencies
*/


#include <bits/stdc++.h>
#include <bitset>
#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'
#define mod 1000000007

using namespace std;

int n;
vector<vector<int> > v(100005),rev(100005);
bool visited[100005];
ll cost[100005];
stack<int>st;
vector<vector<int> > comp;
vector<int>temp;

void dfs(int node)
{
    if(visited[node])return;
    visited[node]=1;
    for(int i=0;i<v[node].size();i++)
        dfs(v[node][i]);
    st.push(node);
}

void dfs2(int node)
{
    if(visited[node])return;
    visited[node]=1;
    temp.push_back(node);
    for(int i=0;i<rev[node].size();i++)
        dfs2(rev[node][i]);
    st.push(node);
}

int main()
{
    cin>>n;
    ll ans=0,ways=1;
    for(int i=1;i<=n;i++)
        cin>>cost[i];
    int m;
    cin>>m;
    while(m--)
    {
        int a, b;
        cin>>a>>b;
        v[a].push_back(b);
    }
    for(int i=1;i<=n;i++)
        dfs(i);
    for(int i=1;i<=n;i++)
        for(int j=0;j<v[i].size();j++)
            rev[v[i][j]].push_back(i);
    memset(visited,0,sizeof visited);
    while(st.size())
    {
        int node=st.top();
        st.pop();
        temp.clear();
        temp.resize(0);
        dfs2(node);
        comp.push_back(temp);
    }
    for(int i=0;i<comp.size();i++)
        {
            if(!comp[i].size())continue;
            ll mn=1e10;
            for(int j=0;j<comp[i].size();j++)
                mn=min(mn,cost[comp[i][j]]);
            ans+=mn;
            ll freq=0;
            for(int j=0;j<comp[i].size();j++)
                freq+=(cost[comp[i][j]]==mn);
            ways*=freq;
            ways%=mod;
        }
    cout<<ans<<' ' <<ways;
    return 0;
}
