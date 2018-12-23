/*
    topological sort to print the drinks in the required order, everytime we start from the beginning of the array,
    if this node has a degree = 0 then we can print it now, and for every other drink that is greater than it, we decrement
    their degree.
*/

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<string>vv;
map<string,vector<string> > v;
map<string,bool>visited;
int n;

int main()
{
    
    int casee=1;
    while(cin>>n){
    vv.clear();
    vv.resize(0);
    v.clear();
    visited.clear();
    cout<<"Case #"<<casee<<": "<<"Dilbert should drink beverages in this order: ";
    casee++;
    for(int o=0;o<n;o++)
    {
        string s;
        cin>>s;
        vv.push_back(s);
    }
    map<string,int>degree;
    int m;
    cin>>m;
    while(m--)
    {
        string s,c;
        cin>>s>>c;
        v[s].push_back(c);
        degree[c]++;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(visited[vv[j]])continue;
            if(degree[vv[j]]==0)
            {
                cout<<vv[j]<< (i==n-1?'.':' ');
                for(int k=0;k<v[vv[j]].size();k++)
                    degree[v[vv[j]][k]]--;
                visited[vv[j]]=1;
                break;
            }
        }
    }
    cout<<endl<<endl;
    }

    return 0;
}
