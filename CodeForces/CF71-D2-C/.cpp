/*
      we check all the different possible side lengths of the polygon, and for every size, we check all the unique polygons
      in the circle, if any of them contains no knights in a bad mood, then the answer is yes.
      if no such polygon is found, then then answer is no.
*/

#include <bits/stdc++.h>
#include <bitset>
#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'
#define mod 1000000009

using namespace std;

int main()
{
    int n;
    cin>>n;
    bool arr[2*n+10];
    for(int i=1;i<=n;i++)cin>>arr[i];
    int cur=1;
    for(int i=n+1;i<2*n+10;i++)arr[i]=arr[cur],cur++;
    for(int i=1;i<=n;i++)             //i is the length of the side of the polygon, and the polygon will have n/i knights(points).
    {
        if(n%i!=0 ||  n/i<3)continue; 
        for(int j=1;j<=i;j++)        //we need to check all different polygons with side length=i, and it's enough to check the first i knights to get all the different polygons
        {
            bool b=0;
            int cnt=0;
            for(int k=j;;k+=i)       //we keep adding i to the curent knight to get the next one, and if all of them are in a good mood, then this polygon is good
            {
                if(cnt==n/i)break;
                if(!arr[k]){b=1;break;}
                cnt++;
            }
            if(!b)return cout<<"YES",0;
        }

    }
    cout<<"NO";
    return 0;
}
