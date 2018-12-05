//i use a priority queue to insert the sum of a segment , along with the start and end position of this segment
//at first i insert all the array(the segment starting at 1 and ending at n)
//then in each step i print , and add in the priority queue the segment of length-1 once by increasing the start {s+1,e}
//and once by decreasing the end {s,e-1}

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
    map<pair<int,int>,bool>visited;
    ll n,k;
    cin>>n>>k;
    ll arr[n+1];arr[0]=0;
    for(int i=1;i<=n;i++)cin>>arr[i],arr[i]+=arr[i-1];
    priority_queue<pair<ll,pair<int,int> > >pq;
    pq.push({arr[n],{1,n}});
    bool b=0;
    while(pq.size())
    {
        if(!k)break;
        ll c=pq.top().first;
        int s=pq.top().second.first,e=pq.top().second.second;
        pq.pop();
        if(visited[{s,e}])continue;
        k--;
        if(b)cout<< ' ';b=1;
        cout<<c;
        visited[{s,e}]=1;
        if(s<e)pq.push({arr[e-1]-arr[s-1] ,{s,e-1} }),pq.push( {arr[e]-arr[s],{s+1,e} });
        else if(s==e) pq.push({arr[s]-arr[s-1], {10,0}});
    }
    return 0;

}
