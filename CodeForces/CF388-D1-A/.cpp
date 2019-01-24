/*
      binary search on the number of towers, and the bases of the towers will be the biggest numbers, 
      then once we have the bases, we iterate over the remaing blocks, sorted in descending order, and ry to put each block
      on the current tower, (we iterate over the towers from biggest to smallest as well) ,if the number of spots left 
      in the current tower is not zero, then we add this block to this tower by updating the number of spots left
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
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    int ans=1e9;
    int s=1,e=n,mid;
    while(s<=e)
    {
        int left[n];
        memset(left,0,sizeof left);
        mid=s+(e-s)/2;
        int cnt=mid;
        for(int i=n-1;i>n-1-mid;i--)
            left[i]=arr[i];
        int cur=n;
        for(int i=n-1-mid;i>=0;i--)
        {
            cur--;
            if(cur<=n-1-mid)
                cur=n-1;
            if(left[cur])
                cnt++,
                left[cur]=min(left[cur]-1,arr[i]);
            else break;
        }
        if(cnt==n)
            ans=mid,
            e=mid-1;
        else s=mid+1;
    }
    cout<<ans;
    return 0;
}
