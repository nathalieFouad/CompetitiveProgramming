/*
    to form the maximum number : start from the first digit and add 9's, then the remaining value, then zeros
    to form the minumum number : strat from the last digit and add 9's, then the remaining value, if the number
    has leading zeros, put 1 in the first digit and subtract 1 from the first non-zero digit
*/

#include <bits/stdc++.h>
#include <bitset>
#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'
#define mod 998244353
#define pi acos(-1)
using namespace std;


int main()
{
    int n,m,left;
    cin>>m>>n;
    if(m>1 && !n)return cout<<-1<<' ' <<-1,0;
    if(n==0)return cout<<0 <<' ' <<0,0;
    int arr[m];
    memset(arr,0,sizeof arr);
    left=n;
    int idx=-1;
    for(int i=m-1;i>=0;i--)
    {
            if(!left){idx=i+1;break;}
            if(left>=9)arr[i]=9,left-=9;
            else arr[i]=left,left=0;
    }
    if(left)return cout<<-1<<' ' <<-1,0;
    if(idx!=-1)
    {
            arr[0]=1;
            arr[idx]--;
    }
    for(int i=0;i<m;i++)cout<<arr[i];
    cout<<' ';
    memset(arr,0,sizeof arr);
    left=n;
    for(int i=0;i<m;i++)
    {
           if(!left)break;
           if(left>=9)arr[i]=9,left-=9;
           else arr[i]=left,left=0;
    }
    for(int i=0;i<m;i++)cout<<arr[i];                                                                                                             
    return 0;
}
