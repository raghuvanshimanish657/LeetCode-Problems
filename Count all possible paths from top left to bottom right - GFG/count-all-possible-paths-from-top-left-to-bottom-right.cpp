//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
const int mod = 1e9 + 7;
class Solution {
public:
	long long int numberOfPaths(int m, int n) {
		int ans = 0;
		vector<long long int>prev(n + 1), curr(n + 1);
		for (int i = m - 1; i >= 0; i--) {
			for (int j = n - 1; j >= 0; j--) {
				if (i == m - 1 and j == n - 1) { curr[j] = 1; continue;}
				curr[j] = prev[j] % mod + curr[j + 1] % mod;
			}
			prev  = curr;
		}
		return prev[0] % mod;
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}

// } Driver Code Ends