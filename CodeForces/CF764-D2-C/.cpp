/*
        for each node i count the number of different colors connected to it
        if more than one node are connected to 2+ colors, then ans is no
        else if one node is connected to 2+ then this is the root, but we have to check to make suree
        if there is no such node, then we search for a node that is connected to one color, and
        all of the other nodes connected to colors are connected to this node, then this is the potential root
        to check if the chosen node is the root, i make sure that all the nodes that are connected to diff colors,
        are actually children of the chosen root , if this is true then the chosen node is actually the root
        otherwise there is no solution.
*/

#include <bits/stdc++.h>
#include <bitset>
#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'
#define mod 998244353

using namespace std;

vector<vector<int> > v(100005);
int cnt[100005];

int main()
{
    int n,root=-1,aktar=0,kolo=0;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<n-1;i++)
    {
        int a, b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    for(int i=1;i<=n;i++)
    {
        set<int>se;
        for(int j=0;j<v[i].size();j++)
        {
            if(arr[v[i][j]]!=arr[i])se.insert(arr[v[i][j]]);
        }
        cnt[i]=se.size();
        if(cnt[i]>=2)
        root=i;
        aktar+=(cnt[i]>=2);
        kolo+=(cnt[i]?1:0);
    }
    if(!kolo)return cout<<"YES\n1",0;
    if(aktar>1)return cout<<"NO",0;
    if(root==-1)
    {
        for(int i=1;i<=n;i++)
        {
            if(cnt[i]==0)
                continue;
            int c=0;
            for(int j=0;j<v[i].size();j++)
                if(cnt[v[i][j]])c++;
            if(c==kolo-1){root=i;break;}
        }
    }
    if(root==-1)return cout<<"NO",0;
    for(int i=1;i<=n;i++)
    {
        if(i==root)continue;
        bool found=0;
        if(cnt[i]){
            for(int j=0;j<v[root].size();j++)
                if(v[root][j]==i)
                found=1;
        if(!found)return cout<<"NO",0;
        }
    }
    cout<<"YES\n"<<root;

    return 0;
}
