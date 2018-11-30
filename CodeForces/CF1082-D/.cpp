//i check if it's possible , if the number of not-one-nodes-values - the number of edges that connects them*2 < number of ones we can't 
// if we can, the length of the diameter is the number of not-one-nodes+ min(one-nodes,2)-1
//then we connect all the not-one-nodes, then we connect the one nodes to the already connected graph one by one
//if we have 2+ one-nodes, we connect one at the beginnning and one at the end to get max diameter


#include <bits/stdc++.h>
#include <bitset>
#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'
#define mod 1000000007
using namespace std;

int main()
{
  int n,sum=0;
  cin>>n;
  vector<pair<int,int> >notone;
  vector<int>one;
  for(int i=1;i<=n;i++){int a;cin>>a;if(a>1)sum+=a;if(a==1)one.push_back(i);else notone.push_back({i,a});}
  if(sum-(notone.size()-1)*2<one.size())return cout<<"NO",0;
  int c=notone.size()+min((int)one.size(),2)-1;
  cout<<"YES"<<' ' <<c<< endl<<n-1<<endl;
  for(int i=0;i<notone.size()-1;i++)cout<<notone[i].first<<' ' <<notone[i+1].first<<endl,notone[i].second--,notone[i+1].second--;
  int mi=0;
  if(one.size()>=2)mi=1;
  for(int i=0;i<one.size()-mi;i++)
  {
     for(int j=0;j<notone.size();j++)if(notone[j].second>0){notone[j].second--;cout<<notone[j].first<<' ' <<one[i]<<endl;break;}
  }
  if(mi)cout<<one[one.size()-1]<<' ' <<notone[notone.size()-1].first<<endl;
  return 0;

}
