/*
      i keep generating the digits and calculate their sum, until i find an 8  
      once an 8 appears, a cycle of 8 6 2 4 will keep occuring until the end 
      so i check how many times the 8 and 6 and 2 and 4 will appear, and i add that to the sum 
      of all the numbers.
      if the sum is divisible by 3, then the answer is yes , else the answer is no
*/

#include <bits/stdc++.h>
#include <bitset>
#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'
#define mod 1000000007
#define pi 3.141592653589

using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll k , a,b;
        cin>>k>>a>>b;
        ll sum=a+b,st=-1;
        for(int i=3;i<=100;i++)
        {
            ll cur=(a+b)%10;
            if(!cur)break;
            sum+=cur;
            a+=b;
            b=cur;
            if(cur==8){
            st=i;                   //idx of the first 8
            break;
            }
        }
        if(st!=-1)
        {
            ll eight=0,six=0,two=0,four=0;
            eight=six=two=four=(k-st+1)/4;
            if((k-st+1)%4==1)
              eight++;
            if((k-st+1)%4==2)
              eight++,
              six++;
            if((k-st+1)%4==3)
              eight++,
              six++,
              two++;
            eight--;                        //because the first 8 is already added to the sum
            eight%=3;
            six%=3;
            two%=3;
            four%=3;
            sum+=8*eight+6*six+2*two+4*four;
        }
        cout<<(sum%3==0?"YES":"NO")<<endl;
    }
    return 0;
}
