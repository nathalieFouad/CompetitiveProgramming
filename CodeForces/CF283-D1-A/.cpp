/*
      if the operation is of type 1: we add x*a to the sum, the cnt doesn't change, and add to the array add[a] the value x
      (add the value to the last index of the segment affected, this means that all the elements from 1->a have this value added)
      if the operation is of type 2: we add a to the sum, the cnt increases by one.
      if the operation is of type 3: we subtract (arr[index]+add[index]) from the sum, the cnt decreases by one, and since the
      add[idx] value is actually added to all of the elements from 1->idx, then we add this value to the previous add[idx-1]
      and clear add[idx].
*/
#include <bits/stdc++.h>
#include <bitset>
#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'
#define mod 1000000007
using namespace std;

ld arr[200005],add[200005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    arr[0]=0;
    int idx=0;
    ld cnt=1,sum=0;
    while(n--)
    {
        int t;
        cin>>t;
        ld ans;
        if(t==1)
        {
            ld a, x;
            cin>>a>>x;
            sum+=a*x;
            a--;
            add[(int)a]+=x;
        }
        else if(t==2)
        {
            ld a;
            cin>>a;
            idx++;
            arr[idx]=a;
            sum+=a;
            cnt++;
        }
        else
        {
            sum-=(arr[idx]+add[idx]);
            add[idx-1]+=add[idx];
            add[idx]=0;
            idx--;
            cnt--;
        }
        ans=sum/cnt;
        cout<<fixed<<setprecision(10)<<ans<<endl;
    }
    return 0;
}
