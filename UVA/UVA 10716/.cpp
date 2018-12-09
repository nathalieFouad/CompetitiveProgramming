//we iterate over the string and we have 2 pointers, one at the beginning of the string and the other at the end
//if the 2 characters that the pointers are holding are equal then we move on
//else we try to make one character like the other greedily, we see the cost to make s[i] like s[j] and the cost to make s[j] like s[i]
//and we choose the minimum ,and we shift the string elements accordingly
//if at any moment we can't make the 2 characters equal the answer is impossible

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

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int ans=0;
        bool b=0;
        for(int i=0,j=(int)s.size()-1;i<(int)s.size()/2;i++,j--)
        {
            if(s[i]==s[j])continue;
            bool cur=0;
            for(int k=i+1,kk=j-1;k<j;k++,kk--){
            if(s[k]==s[j]){
            char temp=s[i];
            s[i]=s[k];
            for(int l=i+1;l<=k;l++){char temp2=s[l];s[l]=temp;temp=temp2;}
            ans+=k-i;
            cur=1;
            break;
            }
            else if(s[kk]==s[i]){
            char temp=s[j];
            s[j]=s[kk];
            for(int l=j-1;l>=kk;l--){char temp2=s[l];s[l]=temp;temp=temp2;}
            ans+=j-kk;
            cur=1;
            break;
            }
            }
            if(!cur){b=1;break;}
        }
        if(b)cout<<"Impossible"<<endl;
        else
        cout<<ans<<endl;
    }

    return 0;
}
