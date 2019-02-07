/*
        first i noticed that if we have a number that is already divisible by 7, and then we add 6 of the same digit, then
        this number is still divisible by 7.
        so i add every 6 equal digits to the string c.
        then this way we have at most 5 of every digit left, i also discovered that if a sequence of length 6 that is in the
        form ababab or abcabc is added to the number, it doesn't affect its divisibility by 7, so i form from the remaining
        digits as many of these sequences as possible, and that is string ans.
        for the remaining digits, i just add them to a string with the digits 1689 and once i find a permutation that is
        divisible by 7, then that's string h.
        this way string h contains a number that is divisible by 7, and strings c and ans do not change this divisibility,
        so i just print all of them.
        i was ignoring the zero and the seven throughout the whole code, since adding them doesn't change anything, so at the
        end, i just print the sevens and zeros that i have.
*/
#include <bits/stdc++.h>
#include <bitset>
#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'
#define mod 1000000007

using namespace std;

int freq[10];

int main()
{
    string s,c="";
    cin>>s;
    for(int i=0;i<(int)s.size();i++)
        freq[s[i]-'0']++;
    freq[1]--;
    freq[6]--;
    freq[8]--;
    freq[9]--;
    for(int i=1;i<10;i++)
    {
        if(i==7)continue;
        int t=freq[i]/6;
        freq[i]%=6;
        for(int j=0;j<t*6;j++)        //add every six equal digits to the string c
            c+=(char)(i+'0');
    }
    string ans="";
    for(int i=0;i<1e4;i++)
    {
        for(int j=1;j<10;j++)
        {
            for(int k=1;k<10;k++)
            {
                if(j==7 || k==7 || freq[k]<3||freq[j]<3||j==k)continue;
                ans+=(char)(j+'0');
                ans+=(char)(k+'0');
                ans+=(char)(j+'0');
                ans+=(char)(k+'0');
                ans+=(char)(j+'0');
                ans+=(char)(k+'0');
                freq[j]-=3;
                freq[k]-=3;
            }

        }
        for(int j=1;j<10;j++)
            for(int k=1;k<10;k++)
                for(int u=1;u<10;u++)
                {
                    if(j==7||k==7||u==7||freq[j]<2||freq[k]<2||freq[u]<2||j==k||k==u||j==u)continue;
                    ans+=(char)(j+'0');
                    ans+=(char)(k+'0');
                    ans+=(char)(u+'0');
                    ans+=(char)(j+'0');
                    ans+=(char)(k+'0');
                    ans+=(char)(u+'0');
                    freq[j]-=2;
                    freq[k]-=2;
                    freq[u]-=2;
                }
    }
    string h="1689";
    for(int i=1;i<10;i++)
    {
        if(i==7)continue;
        for(int j=0;j<freq[i];j++)h+=(char)(i+'0');
    }
    sort(h.begin(),h.end());
   do{
     ll u=0;
    for(int i=0;i<(int)h.size();i++)
    {
        u*=10;
        u+=(h[i]-'0');
    }
    if(u%7==0)break;
   }while(next_permutation(h.begin(),h.end()));
   cout<<h<<c<<ans;
   for(int i=0;i<freq[7];i++)cout<<7;
   for(int i=0;i<freq[0];i++)cout<<0;
    return 0;
}
