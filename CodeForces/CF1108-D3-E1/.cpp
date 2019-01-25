/*
      consider the outer loop as the index of the max number in the array, and the inner loop as the index of the min number
      this way we try all different positions together.
      for every pair of i and j , we iterate over all the segments, and we try to make arr[j] as small as possible, 
      so if a segment contains j and does not contain i, then we use this segment, and this increases the diff between them
      by decreasing the value of arr[j]
      we maximize and get the final maximum difference
*/

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
    int n,m;
    cin>>n>>m;
    ll arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<pair<int,int> > seg(m);
    for(int i=0;i<m;i++)
        cin>>seg[i].first>>seg[i].second,
        seg[i].first--,
        seg[i].second--;
    ll ans=0;
    set<int>anss;
    for(int i=0;i<n;i++)  //max element
    {
        for(int j=0;j<n;j++) // min element
        {
            if(i==j)continue;
            ll u=arr[j];
            set<int>se;
            for(int k=0;k<m;k++)
            {
                if(seg[k].first<=j && j<=seg[k].second && (i>seg[k].second || i<seg[k].first))
                    u--,
                    se.insert(k+1);
            }
            if(arr[i]-u>ans)
            ans=arr[i]-u,
            anss=se;
        }
    }
    cout<<ans<<endl<<anss.size()<<endl;
    for(set<int>::iterator it=anss.begin();it!=anss.end();it++)
        cout<<*it<<' ' ;

    return 0;
}
