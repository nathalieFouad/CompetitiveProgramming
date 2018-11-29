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
    string s="..........";
    while(n--)
    {
        char c;int a;
        cin>>c>>a;
        string h=std::bitset<10>(a).to_string();
        if(c=='|')
        {
            for(int i=0;i<10;i++)if(h[i]=='1')s[i]='1';
        }
        else if(c=='&')
        {
            for(int i=0;i<10;i++)if(h[i]=='0')s[i]='0';
        }
        else {
            for(int i=0;i<10;i++)if(h[i]=='1')
            {
            if(s[i]=='.')s[i]='T';
            else if(s[i]=='T')s[i]='.';
            else if(s[i]=='0')s[i]='1';
            else s[i]='0';}
        }
    }
        string orr="",andd="",xorr="";
        for(int j=0;j<10;j++){if(s[j]=='1')orr+='1';else orr+='0';}
        for(int j=0;j<10;j++){if(s[j]=='0')andd+='0';else andd+='1';}
        for(int j=0;j<10;j++){if(s[j]=='T')xorr+='1';else xorr+='0';}
       // cout<<andd<<endl;
    cout<<3<<endl;
    cout<< '|'<<' '<< std::bitset<10>(orr).to_ulong()<<endl;
    cout<< '&'<<' ' <<std::bitset<10>(andd).to_ulong()<<endl;
    cout<< '^'<<' '<<std::bitset<10>(xorr).to_ulong()<<endl;
	return 0;
 
}
