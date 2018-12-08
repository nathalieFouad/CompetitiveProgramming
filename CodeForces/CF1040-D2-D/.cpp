//binary search from start to end, if the response is yes, then the subway must be in range s-k -> e+k the next time,
//we then use random function to guess a number, if the response is yes,then we have found the subway, else we keep doing binary search

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
    srand(time(0));
    ll n,k;
    scanf("%lld%lld",&n,&k);
    ll s=1,e=n,mid;
    while(1)
    {
        if(e-s<=50){
        ll ask=rand()%(e-s+1) + s;
        printf("%lld %lld\n",ask,ask);fflush(stdout);
        char res1[4];
        scanf("%3s",&res1);
        if(res1[0]=='Y')return 0;
        else s=max((ll)1,s-k),e=min(e+k,n);
        }
        mid=(s+e)/(ll)2;
        printf("%lld %lld\n",s,mid);fflush(stdout);
        char res[4];
        scanf("%3s",&res);
        if(res[0]=='Y')s=max(s-k,(ll)1),e=min(n,mid+k);
        else s=max((ll)1,mid-k),e=min(e+k,n);
    }
    return 0;
}
