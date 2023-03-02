//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


typedef long long ll;

class Solution{
public:
    int minCost(vector<vector<int>> &a) {
        int n = a.size(), k = a[0].size();
        if(n>1 && k==1)return -1;
        
        vector<ll> v1(k), v2(k), v(k);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < k; ++j){
                v[j] = INT_MAX*(k>1);
                if(j)v[j] = v1[j-1];
                if(j<k-1)v[j] = min(v[j], v2[j+1]);
                v[j] += a[i][j];
            }
            v1 = v2 = v;
            for(int j = 1; j < k; ++j){
                v1[j] = min(v1[j], v1[j-1]);
            }
            for(int j = k-2; j >= 0; --j){
                v2[j] = min(v2[j], v2[j+1]);
            }
        }
        
        return v2[0];
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends