/*
    for every position from the end of the freq array, we try to form zero, one or two  mixed segments of form (i,i-1,i-2) 
    + the remaining freq/3 and we maximize. 
    we keep track of the number that is decremented from the cur position and the position before the cur,
    and whenever we go to solve i-1, then decana becomes decabli, and decabli becomes the number of segments that we're 
    forming
*/

#include <bits/stdc++.h>
#include <bitset>
#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'

using namespace std;

int freq[1000001];

int mem[1000001][3][3];

int solve(int i,int decana, int decabli)  //decana: the number that is subtracted from the current freq because it was used
{                                         //by the previous ones in a segment.
    if(i==0)return 0;                     //decabli: the number that is subtracted from the freq[i-1] because of the same reason
    if(mem[i][decana][decabli]!=-1)
        return mem[i][decana][decabli];
    if(freq[i]-decana==0)
        return mem[i][decana][decabli]=solve(i-1,decabli, 0);
    if(i<=2)
        return mem[i][decana][decabli]=solve(i-1,decabli,0)+(freq[i]-decana)/3; // there will be no more segments of mixed numbers
    int ret=0;                                                                  // so we just add the cur freq/3 and solve for the previous one
    for(int j=0;j<=min(freq[i]-decana,min(freq[i-1]-decabli,min(2,freq[i-2])));j++)
        ret=max(ret,solve(i-1,decabli+j,j)+(freq[i]-decana-j)/3+j); //we try from the cur position to form j=0, 1 or 2 mixed
    return mem[i][decana][decabli]=ret;                            //segments of form (i, i-1, i-2) and maximize
                                                                   //2 is enough because every 3 mixed segments can be 
}                                                                 //transformed into 3 not mixed segments so we have at most 2 mixed. 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    memset(mem,-1,sizeof mem);
    int n,m,ans=0;
    cin>>n>>m;
    while(n--)
    {
        int a;
        cin>>a;
        freq[a]++;
    }
    cout<<solve(m,0,0);
    return 0;
}
