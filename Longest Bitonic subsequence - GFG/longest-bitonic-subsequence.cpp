//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
	int LongestBitonicSequence(vector<int> v) {

	    int n = v.size();
        vector<int> left(n, 1), right(n, 1);
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(v[i] > v[j] && left[i] < left[j]+1) left[i] = left[j]+1;
            }
        }
        
        for(int i=n-1; i>=0; i--){
            for(int j=n-1; j>i; j--){
                if(v[i] > v[j] && right[i] < right[j]+1) right[i] = right[j]+1;
            }
        }
        
        int ans = 0;
        for(int i=0; i<n; i++) {
            ans = max(ans, left[i]+right[i]-1);
        }
        
        return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends