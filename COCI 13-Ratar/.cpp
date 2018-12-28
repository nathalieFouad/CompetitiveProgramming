/*
    from every possible common point, we try every top left rectangle with every bottom right, and every top right with
    every bottom left
*/ 
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int sum[55][55];
map<int,int>mp;

int s(int i,int j,int ii,int jj)
{
    int ret=sum[ii][jj];
    if(j-1>=0)ret-=sum[ii][j-1];
    if(i-1>=0)ret-=sum[i-1][jj];
    if(i-1>=0 && j-1>=0)ret+=sum[i-1][j-1];
    return ret;
}


int main()
{
    int n,ans=0;
    cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>arr[i][j],
            sum[i][j]=arr[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
             if(j-1>=0)sum[i][j]+=sum[i][j-1];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
             if(i-1>=0)sum[i][j]+=sum[i-1][j];

    for(int i=1;i<n;i++)
        for(int j=1;j<n;j++)
        {
            for(int ii=0;ii<i;ii++)
                for(int jj=0;jj<j;jj++)
                    mp[s(ii,jj,i-1,j-1)]++;
            for(int ii=i;ii<n;ii++)
                for(int jj=j;jj<n;jj++)
                    ans+=mp[s(i,j,ii,jj)];
            mp.clear();
            for(int ii=0;ii<i;ii++)
                for(int jj=j;jj<n;jj++)
                    mp[s(ii,j,i-1,jj)]++;
            for(int ii=i;ii<n;ii++)
                for(int jj=0;jj<j;jj++)
                    ans+=mp[s(i,jj,ii,j-1)];
            mp.clear();
        }
    cout<<ans;

    return 0;
}
