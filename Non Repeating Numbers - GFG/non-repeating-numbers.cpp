//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        vector<int> ans;
        int n = nums.size();
        int XOR = nums[0];
        for(int i=1;i<n;i++)
            XOR = XOR ^ nums[i];
            int rightBit = XOR & ~(XOR-1);
            int x,y;
            x=y=0;
        for(int i=0; i<n;i++){
            if(nums[i]&rightBit)
                x = x^nums[i];
            else
                y = y^nums[i]; 
        }
        ans.push_back(x);
        ans.push_back(y);
        sort(ans.begin(), ans.end());
        return ans;
        
            
    }
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends