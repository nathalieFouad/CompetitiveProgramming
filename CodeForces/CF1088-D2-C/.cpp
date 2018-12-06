//we make all the array elements bery large in one step
//then for the next n steps we mod each number to make it equal to the index , so we do mod arr[i]-i
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
    int arr[n+1];
    for(int i=1;i<=n;i++)cin>>arr[i];
    cout<<n+1<<endl;
    cout<<1<<' ' <<n<<' ' <<100000<<endl;
    for(int i=1;i<=n;i++)arr[i]+=1e5;
    for(int i=1;i<=n;i++)
    {
        cout<< 2 <<' ' << i << ' ' <<arr[i]-i<<endl;
    }
    return 0;

}
