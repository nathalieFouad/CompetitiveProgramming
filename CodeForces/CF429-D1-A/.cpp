/*
      we dfs from the root.  for each node if this node != goal , then we add it to the answer, and if this node is on 
      an even level, then we know that all of the even levels from now on should be toggled, same for the odd levels
      so we xor the value of even or odd with one.
      now whenever we reach a new node, we need to update it with the changes done by its parents, so if the cur node
      is in an even level and the bool even is on, then it will be changed, same for the odd, and after the update, we
      check if it !=the goal and do the same thing.
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
vector<vector<int> > v(100005);
int cur[100005],goal[100005];
bool visited[100005];
vector<int>ans;

void dfs(int node, bool even, bool odd, int level)
{
    if(visited[node])return;
    visited[node]=1;
    //update
    if(even && level%2==0)cur[node]^=1;
    if(odd && level%2==1)cur[node]^=1;
    if(cur[node]!=goal[node])
    {
        ans.push_back(node);
        if(level%2==0)even^=1;
        else odd^=1;
    }
    for(int i=0;i<v[node].size();i++)
        dfs(v[node][i],even,odd,level+1);
}

int main()
{
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
        cin>>cur[i];

    for(int i=1;i<=n;i++)
        cin>>goal[i];
    dfs(1,0,0,0);
    cout<<(int)ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;
    return 0;
}
