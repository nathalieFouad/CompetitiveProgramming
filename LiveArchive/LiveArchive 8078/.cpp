//we iterate from the end of the string, whenever we find a closed bracket,we push it in a stack (st) along with the answer 
//of i+1, so we are pushing with the bracket the length of the longest balanced sequence after it directly, so that we can add it later
//we have another stack called add,the top of this stack represents the length of the longest balanced sequence that is inside
//the current segment that we're working on
//once we find an opened bracket, if the top of the stack has the corresponding closed bracket, then the ans to this pos
//is the value at the top of the stack "add", that represents the length within those brackets + the value attached to 
//the closed bracket in (st),which represents the lenngth of the subsequence after those brackets from the outside, 
//and we add 2 , the count of these 2 brackets.

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
    for(int casee=1;casee<=t;casee++)
    {
        string s;
        cin>>s;
        int ans[(int)s.size()];
        memset(ans,0,sizeof ans);
        stack<pair<char,int> >st;
        stack<int>add;
        for(int i=(int)s.size()-1;i>=0;i--)
        {
            if(i==(int)s.size()-1){st.push({s[i],0});add.push(0);continue;}
            if(s[i]=='>'||s[i]=='}'||s[i]==')'||s[i]==']'){st.push({s[i],ans[i+1]});add.push(0);continue;}
            if(st.empty()){st.push({s[i],0});if(add.size())add.pop();continue;}
            if(s[i]=='{'&&st.top().first=='}'){ans[i]=st.top().second+2+add.top();add.pop();if(add.size())add.top()=ans[i]; st.pop();}
            else if(s[i]=='<'&&st.top().first=='>'){ans[i]=st.top().second+2+add.top();add.pop();if(add.size())add.top()=ans[i]; st.pop();}
            else if(s[i]=='['&&st.top().first==']'){ans[i]=st.top().second+2+add.top();add.pop();if(add.size())add.top()=ans[i]; st.pop();}
            else if(s[i]=='('&&st.top().first==')'){ans[i]=st.top().second+2+add.top();add.pop();if(add.size())add.top()=ans[i]; st.pop();}
            else {st.push({s[i],0});if(add.size())add.pop();}
        }
        cout<<"Case "<<casee<<':'<<endl;
        for(int i=0;i<(int)s.size();i++)cout<<ans[i]<<endl;
    }

    return 0;
}
