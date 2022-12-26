//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long
class Solution{
public:
    void precompute()
    {
        // Code Here
    }
    ll solve(ll l, ll r){
        // Code Here
        ll ans=0;
        for(ll i=1;i<=r;i*=2){
            for(ll j=i*2;j<=r;j*=2){
                for(ll k=j*2;k<=r;k*=2){
                    ll no_with_3_bits=i|j|k;
                    if(no_with_3_bits>=l && no_with_3_bits<=r) ans++;
                }
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    Solution ob;
    ob.precompute();
    cin>>t;
    while(t--)
    {
        long long l,r;
        cin>>l>>r;
        cout << ob.solve(l, r) << endl; 
    }
    return 0;
}
// } Driver Code Ends