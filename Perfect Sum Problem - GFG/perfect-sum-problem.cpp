//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	unsigned int mod=1e9+7;
    private:
    int dp[1001][1001];
    int solve(int ind, vector<int> &nums, int sum) {
        if(sum == 0) return 1;
        if(dp[ind][sum] != -1) return dp[ind][sum];
        if(ind >= nums.size() or nums[ind] > sum) return 0;
        int ans = solve(ind+1, nums, sum-nums[ind]) % mod;
        ans = (ans + solve(ind+1, nums, sum)) % mod;
        return dp[ind][sum] = ans;
        
    }
	public:
	int perfectSum(int arr[], int n, int sum)
	{   
	    memset(dp,-1,sizeof(dp));
        vector<int> vec;
        for(int i=0; i<n; ++i) vec.emplace_back(arr[i]);
        sort(begin(vec), end(vec));
        return solve(0, vec, sum) % mod;
        
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends