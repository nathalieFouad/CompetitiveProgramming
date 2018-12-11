//we use array before greater(bg) to store the number of people that have greater strength and that are before index i
//we use array after smaller(as) to store the number of people that have smaller strength and that are after index i
//we calculate array bg by creating an ordered set and inserting the negative of the numbers,and we insert from the beginning 
//and get the number of elements that are less than the cur, then we insert it , and we're sure that all of these numbers 
//have an index smaller than the cur, since they are in the tree
//in the same way we calculate array (as) , by iterating from the end of the array, (so all what's in the set will have a greater index than the cur)
//and we  get the number of elements that are less than the cur, then we insert the cur.
//we then calculate the sum of all the bg[i]*as[i] for all i , and this is the answer.

#include <bits/stdc++.h>
#include <bitset>
#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'
#define mod 1000000007
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main()
{
    int n;
    cin>>n;
    ordered_set awl,a5er;
    ll bg[n],as[n];
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i],bg[i]=awl.order_of_key(-arr[i]),awl.insert(-arr[i]);
    for(int i=n-1;i>=0;i--)as[i]=a5er.order_of_key(arr[i]),a5er.insert(arr[i]);
    ll ans=0;
    for(int i=0;i<n;i++)ans+=bg[i]*as[i];
    cout<<ans;
    return 0;
}
