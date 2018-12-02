//i calculate the maximum height, then i use dp.
//dp[nb of blocks of the level that i have to build right now][red left]
//i calculate the number of green blocks left (gl) , 
//the ans to this state is the sum of answers of dp[nb of blocks -1][red left-nb of blocks] <-if the red left is enough
// +dp[nb of blocks-1][red left]<-if the (gl) is enough

#include <bits/stdc++.h>
#include <bitset>
#define ll long long
#define ld long double
#define ull unsigned long long[
#define endl '\n'
#define mod 1000000007
using namespace std;
ll blocks,r,g,sum,h;
int dp[2][200001];


int main()
{
    cin>>r>>g;sum=r+g;
    for(;h*(h+1)/2<=sum;h++);h--;
    for(int i=0;i<=r;i++)dp[0][i]=1;
    for(int i=1;i<=h;i++)
    {
        for(int j=0;j<=r;j++)
        {
            int gl=g-(h*(h+1)/2-i*(i+1)/2-(r-j));
            if(!j || !gl){dp[1][j]=1;continue;}
            if(j>=i)dp[1][j]=dp[0][j-i];
            if(gl>=i)dp[1][j]+=dp[0][j];
            dp[1][j]%=mod;
        }
        for(int j=0;j<=r;j++)dp[0][j]=dp[1][j],dp[1][j]=0;
    }
    cout<<dp[0][r];

    return 0;

}
