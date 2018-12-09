//the equation is d= x_i^2 - 2*x_i *(every other x_j , j>i)+ x_j^2 + y_i^2 - 2*y_i*(every other y_j, j>i )+ y_j^2
//according to this formula each x_i^2 and y_i^2 are added n-1 times
//so we first add to the answer all the x_i ^2 and y_i ^2 , n-1 times
//the problem right now is how to calculate all x_i*x_j(j>i) without iterating over them (nested loops)
//so we make the array x that stores the multiplication of the first element by all the others
// so x[2]=x_1*x_2 , x[3]=x_1*x_3 , x[4]=x_1*x_4 and so on ,and arr y is the same but for Y
//and we make accumulative sum for both arrays x and y
//now whenever we want to calculate the value of the multiplication of any 2 X, we can use the array x this way
//say we want to get the value of x_4*x_5 , we multiply x[4]*x[5] this is equal to x_1*x_4*x_1*x_5 so we divide by x_1*x_1
//to get the desired value, we just have to make sure we're not dividing by 0
//so in this case, if x_1 or y_1 =0 , i store in the array x or y the values of the other numbers , instead of x_1*number
//so this way i don't lose all the values and get zero in the whole array
// so for each x_i we add to it the values from i+1 to n , and just divide by x_1^2 , same applies for y

#include <bits/stdc++.h>
#include <bitset>
#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'
#define mod 1000000007
#include <chrono>
#include <random>
using namespace std;
ll n;
ll x[100005],y[100005];
int main()
{
    cin>>n;
    vector<pair<ll,ll> > v(n+1);
    for(int i=1;i<=n;i++)cin>>v[i].first>>v[i].second;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=(n-1)*v[i].first*v[i].first+(n-1)*v[i].second*v[i].second;
        if(i<2)continue;
        x[i]=(v[1].first==0?v[i].first:v[i].first*v[1].first);
        y[i]=(v[1].second==0?v[i].second:v[i].second*v[1].second);
        x[i]+=x[i-1];
        y[i]+=y[i-1];
    }
    ll add=(v[1].first==0?0:x[(int)n]);
    for(int i=2;i<n;i++)
    {
        if(v[1].first==0){add+=(x[i]-x[i-1])*(x[(int)n]-x[i]);continue;}
        add+=(x[i]-x[i-1])*(x[(int)n]-x[i])/(v[1].first*v[1].first);
    }
    ans+=add*(-2);
    add=(v[1].second==0?0:y[(int)n]);
    for(int i=2;i<n;i++)
    {
         if(v[1].second==0){add+=(y[i]-y[i-1])*(y[(int)n]-y[i]);continue;}
        add+=(y[i]-y[i-1])*(y[(int)n]-y[i])/(v[1].second*v[1].second);
    }
    ans+=add*(-2);
    cout<<ans;

    return 0;
}
