//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S) {
        if(N==1 && S==0) return "0";        
        if (S <= 0 || S > 9 * N) {
            return "-1"; // No valid number is possible in this case.
        }
    
        string ans = "";
    
        while (N > 0) {
            if (S >= 9) {
                ans.push_back('9');
                S -= 9;
            } else {
                ans.push_back('0' + S);
                S = 0;
            }
            N--;
        }
    
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends