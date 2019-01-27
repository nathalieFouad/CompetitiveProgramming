/*
        for every position, we save the index of the first decrease after it, in array d[i]
        and save the last increase before it, in array u[i]
        and for every query, we check if there is a decrement then an increment within this range, then the answer is no
        else the answer is yes
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
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int d[n],u[n];
    d[n-1]=-1;
    for(int i=n-2;i>=0;i--)
        {if(arr[i+1]<arr[i])
            d[i]=i;
        else d[i]=d[i+1];}
    u[0]=-1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[i-1])
            u[i]=i-1;
        else u[i]=u[i-1];
    }
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        l--;r--;
        if(d[l]==-1|| u[r]==-1)cout<<"Yes\n";
        else if(d[l]<=u[r] && d[l]<=r && u[r]>=l)cout<<"No\n";
        else cout<<"Yes\n";
    }
    return 0;
}
