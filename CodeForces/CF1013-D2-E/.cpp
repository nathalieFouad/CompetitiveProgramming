/*
        dp. i is the current index, j is the number of houses we've built so far, k is whether the tower before last was a house,
        if this is the case, then the last tower is min( its height , and the height of the previous) since it has
        to be less than the tower with the house. then for every i, we try to either build a house here( add the cost of
        reducing the previous house , and the next one), or not build a house and move to the next hill.
*/
#include <bits/stdc++.h>
#include <bitset>
#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'
#define mod 1000000007

using namespace std;

int n;
ll arr[5005];
ll dp[5002][2502][2];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    memset(dp,-1,sizeof dp);
    for(int i=n;i<5002;i++)
        for(int j=0;j<2502;j++)
            for(int k=0;k<=1;k++)
                dp[i][j][k]=1e18;
                
    for(int i=0;i<5002;i++)
        for(int j=0;j<=1;j++)
            dp[i][(int)ceil((ld)n/2.0)][j]=0;

    for(int i=n;i>=0;i--)
        for(int j=ceil((ld)n/2.0);j>=0;j--)
            for(int k=0;k<=1;k++)
            {
                if(dp[i][j][k]!=-1)
                  continue;
                ll l=0;
                if(i-1>=0)
                  l=arr[i-1];
                if(k)
                  l=min(arr[i-2]-1,arr[i-1]);
                ll add=((i-1>=0 && l>=arr[i])?l-arr[i]+1:0);
                if(i+1<n && arr[i+1]>=arr[i])
                  add+=(arr[i+1]-arr[i]+1);
                dp[i][j][k] = min(dp[i+1][j][0],dp[i+2][j+1][1]+add);
            }


    for(int i=1;i<=ceil((ld)n/2.0);i++)
        cout<<dp[0][(int)ceil((ld)n/2.0)-i][0] <<' ';
    return 0;
}
