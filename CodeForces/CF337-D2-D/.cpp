//the solution i found is , i find the farthest 2 affected nodes from each other i used 2 dfs, then we calculate the shortest path
// between the first node and all the other nodes, and the second node and all the other nodes (i used bfs),then if there is a 
//node that is close enough to both affected nodes , we know for sure it will be close enough to all of the other affected
//nodes so we count it 

#include <bits/stdc++.h>
#include <bitset>
#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'
#define mod 1000000007
using namespace std;

vector<vector<int> > v;
bool visited[100001];
bool affected[100001];
int level1[100001],level2[100001];
int mx,node,d;
void dfs(int n,int lvl)
{
    if(visited[n])return;
    visited[n]=1;
    if(lvl>mx && affected[n])mx=lvl,node=n;
    for(int i=0;i<v[n].size();i++)dfs(v[n][i],lvl+1);
}
int dfs2(int n,int lvl)
{
    //cout<<n<<' ' <<lvl<<endl;
    if(visited[n])return 0;
    visited[n]=1;
    int ret=(lvl<=d);
    for(int i=0;i<v[n].size();i++)ret+=dfs2(v[n][i],lvl+1);
    return ret;
}

int main()
{
  int n,m;
  cin>>n>>m>>d;
  int aff[m];
  for(int i=0;i<m;i++)cin>>aff[i],affected[aff[i]]=1;
  v.resize(n+1);
  for(int i=0;i<n;i++)
  {
    int a, b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  dfs(aff[0],0);
  int node1=node;
  mx=0;
  memset(visited,0,sizeof visited);
  dfs(node,0);
  int node2=node;
  queue<int>q;
  q.push(node1);
  memset(visited,0,sizeof visited);
  if(m==1)return cout<<dfs2(aff[0],0),0;
  while(q.size())
  {
    int cur=q.front();q.pop();visited[cur]=1;
    for(int i=0;i<v[cur].size();i++)if(!visited[v[cur][i]])q.push(v[cur][i]),level1[v[cur][i]]=level1[cur]+1;
  }
  q.push(node2);
  memset(visited,0,sizeof visited);
  while(q.size())
  {
    int cur=q.front();q.pop();visited[cur]=1;
    for(int i=0;i<v[cur].size();i++)if(!visited[v[cur][i]])q.push(v[cur][i]),level2[v[cur][i]]=level2[cur]+1;
  }
  int ans=0;
  for(int i=1;i<=n;i++)if(level1[i]<=d&&level2[i]<=d)ans++;
  cout<<ans;
  return 0;

}
