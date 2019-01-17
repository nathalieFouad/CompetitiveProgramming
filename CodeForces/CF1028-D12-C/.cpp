/*
       at first i suppose that the area of the first rectangle is the common area, and in each iteration, 
       if the current rectangle intersects with the common area so far, then i reduce the common area, 
       so it represents the common between the previous common area and the current rectangle, so it holds the common so far
       if the current rectangle doesn't intersect with the common area, then we mark this rectanlge, because we're sure that
       either this rectangle does not belong to the final answer, or one of the previous ones does not, and this rectangle does
       so we do the whole algorithm again starting from this rectangle, if excluding it did not give us an answer.

*/

#include <bits/stdc++.h>
#include <bitset>
#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'
#define mod 1000000007

using namespace std;

struct point{
int x,y;
};


int main()
{
    int n;
    cin>>n;
    vector<pair<point,point> > v(n);
    for(int i=0;i<n;i++)
        cin>>v[i].first.x>>v[i].first.y>>v[i].second.x>>v[i].second.y;
    int t=-1,d=-1,l=-1,r=-1,other,cnt=1;
            t=v[0].second.y;
            d=v[0].first.y;
            r=v[0].second.x;
            l=v[0].first.x;
    for(int i=1;i<n;i++)
    {
            if(v[i].first.x>r || v[i].first.y>t || v[i].second.x<l || v[i].second.y<d)other=i;
            else{
            cnt++;
            t=min(t,v[i].second.y);
            d=max(d,v[i].first.y);
            r=min(r,v[i].second.x);
            l=max(l,v[i].first.x);
            }

    }
    if(cnt>=n-1)return cout<<r<<' ' <<d,0;
    else {
            t=v[other].second.y;
            d=v[other].first.y;
            r=v[other].second.x;
            l=v[other].first.x;
            for(int i=0;i<n;i++)
            {
                if(i==other)continue;
                else
                {
                    if(v[i].first.x>r || v[i].first.y>t || v[i].second.x<l || v[i].second.y<d)continue;
                    else{
                    t=min(t,v[i].second.y);
                    d=max(d,v[i].first.y);
                    r=min(r,v[i].second.x);
                    l=max(l,v[i].first.x);
                    }
                }
            }
    }
    cout<<r<<' ' <<d;
    return 0;
}
