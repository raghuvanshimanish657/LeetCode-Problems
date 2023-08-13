//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define mod 1000000007
class Solution {
  public:
  
    long long fibo(vector<long long> &ans,long long n){
        if(n<2)return n;
        if(ans[n]!=-1)return ans[n];
        ans[n]=fibo(ans,n-1)%mod+fibo(ans,n-2)%mod;
        return ans[n];
    }
    
    long long int nthFibonacci(long long int n){
        vector<long long> ans(n+1,-1);
        ans[0]=0;ans[1]=1;
        return fibo(ans,n)%mod;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends