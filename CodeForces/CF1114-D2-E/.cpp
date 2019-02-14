/*
      use binary search to get the last element in the sequence, then use the remaining 30 queries to get random values
      from the sequence, calculate the difference between all of the them , and get their gcd and this is the common difference
      we get the first element by the formula first = last-d*(n-1)
*/

#include <bits/stdc++.h>
#include <bitset>
#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'
#define mod 1000000007

using namespace std;

map<int,bool>visited;

int main()
{
    srand(time(0));
    int n,left=60,last;
    cin>>n;
    int s=0,e=1e9,mid;
    while(s<=e)
    {
        mid=s+(e-s)/2;
        cout<<'>'<<' '<<mid<<endl;
        cout.flush();
        left--;
        bool res;
        cin>>res;
        if(res)s=mid+1;
        else last=mid,
             e=mid-1;
    }
    vector<int>v;
    v.push_back(last);
    int ask=1, cnt=0;
    while(left--)
    {
        if(cnt==n)break;
        ask=(1ll*rand()*rand())%n+1;
        while(visited[ask]==1)
            ask=(1ll*rand()*rand())%n+1;
        cout<<'?'<<' ' <<ask<<endl;
        cout.flush();
        cnt++;
        visited[ask]=1;
        int res;
        cin>>res;
        v.push_back(res);
    }
    int g=0;
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v.size();j++)
        g=__gcd(g,abs(v[i]-v[j]));
    }
    cout<<'!'<<' ' << last-g*(n-1)<<' ' <<g<<endl;
    cout.flush();
    return 0;
}
