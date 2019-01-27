/*
        i sort the players according to their strength, and we iterate from the strongest player, and we add
        the current player to the team that has the least total sum, in order to minimize the difference between the 2 sums,
        after this we need to make sure that the difference between their sizes is at most 1.
        if this is not the case, we keep taking the weakest player from the team that has more players, and 
        put him in the other team until the difference is <=1
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    pair<int,int> arr[n];
    vector<pair<int,int> > vv;
    for(int i=0;i<n;i++)
        cin>>arr[i].first,
        arr[i].second=i+1;
    sort(arr,arr+n);
    priority_queue<pair<int,int> >t1,t2;
    int s1=0,s2=0;
    for(int i=n-1;i>=0;i--)
    {
        if(s1<=s2){
        s1+=arr[i].first;
        t1.push({-arr[i].first,arr[i].second});
        }
        else{
        s2+=arr[i].first;
        t2.push({-arr[i].first,arr[i].second});
        }
    }
    while(abs((int)t1.size()-(int)t2.size())>1)
    {
        if((int)t1.size()>(int)t2.size())
            t2.push(t1.top()),
            t1.pop();
        else t1.push(t2.top()),
        t2.pop();
    }
    cout<<(int)t1.size()<<endl;
    while((int)t1.size())
    cout<<t1.top().second<<' ',
    t1.pop() ;
    cout<<endl<<(int)t2.size()<<endl;
    while((int)t2.size())
    cout<<t2.top().second<<' ',
    t2.pop();

    return 0;
}
