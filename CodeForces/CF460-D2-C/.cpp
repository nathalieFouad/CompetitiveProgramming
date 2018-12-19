//i do binary search on answer, and i maximize
//in the array a , i keep the value that should be added right now , or subtracted , otherwise it's zero means nothing happens here
//the cur is the value that i add as i go to the current flower, every iteration i add to the cur the value in a[i]
//if the value in arr[i]+cur is less than the mid, we increase it if we have moves left, else it's not possible
//every time we add a value in idx i , we subtract from a[i+w] the value added now, so that it will be added to the values
//within the range i->i+w-1 only

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
ll n,arr[200005],d,w;
int main()
{
    cin>>n>>d>>w;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    ll s=1, e=1e9+1e5+1, mid,ans=0;
    while(s<=e)
    {
        ll left=d;
        ll a[n+1] , cur=0;
        memset(a,0,sizeof a);
        mid=s+(e-s)/2;
        bool b=0;
        for(int i=1;i<=n;i++)
        {
            cur+=a[i];
            if(arr[i]+cur>=mid)continue;
            if(left<mid-(arr[i]+cur)){b=1;break;}
            left-=(mid-(arr[i]+cur));
            if(i+w<=n)
            a[i+w]-=(mid-(arr[i]+cur));
            cur+=mid-(arr[i]+cur);
        }
        if(!b)ans=mid,s=mid+1;
        else e=mid-1;
    }
    cout<<ans;
    return 0;
}
