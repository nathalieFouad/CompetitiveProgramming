//i save all the existing rectangles till now in a vector in the form of the bottom left pt and the top right,
// i sort the cuts and i iterate over them andfor each one i iterate over the rectangles, if i can make the cut right now 
//i mark it visited and remove this rectangle and insert the 2 new rectangles, else i keep iterating until all the cuts are done


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
    int w,h,n;
    cin>>w>>h>>n;
    vector<pair<  pair<int,int> ,pair<int,int>   > >v,cut(n);
    v.push_back({ {0,0},{w,h} });
    for(int i=0;i<n;i++)cin>>cut[i].first.first>>cut[i].first.second>>cut[i].second.first>>cut[i].second.second;
    sort(cut.begin(),cut.end());
    bool visited[n];memset(visited,0,sizeof visited);
    int j=0,cnt=0;
    while(1){
        if(cnt==n)break;
       j%=n;
       if(visited[j]){j++;continue;}
        int x1=cut[j].first.first,y1=cut[j].first.second,x2=cut[j].second.first,y2=cut[j].second.second;
        for(int i=0;i<v.size();i++)
        {
            if(x1==x2 && x1<max(v[i].first.first,v[i].second.first) && x1>min(v[i].first.first,v[i].second.first) && min(y1,y2)==min(v[i].first.second,v[i].second.second) && max(y1,y2)==max(v[i].first.second,v[i].second.second) )
            {
            go:;
            v.push_back({ v[i].first ,{x2,y2} });
            v.push_back({   {x1,y1} ,v[i].second});
            v.erase(v.begin()+i);
            visited[j]=1;
            cnt++;
            break;
            }
            else if(y1==y2 && y1<max(v[i].first.second,v[i].second.second) && y1>min(v[i].first.second,v[i].second.second) && min(x1,x2)==min(v[i].first.first,v[i].second.first) && max(x1,x2)==max(v[i].first.first,v[i].second.first))goto go;
        }
        j++;
    }
    vector<int>ans;
    for(int i=0;i<v.size();i++)ans.push_back(abs(v[i].first.first-v[i].second.first)*abs(v[i].first.second-v[i].second.second));
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<' ';
	return 0;

}
