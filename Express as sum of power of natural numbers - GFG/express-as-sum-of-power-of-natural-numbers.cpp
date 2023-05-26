//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int numOfWays(int n, int x){
        vector<int> coins , first(n+1,0) , second(n+1,0) ;
        first[0] = 1;
        for(int i=1;i<=n;i++) {
            if(pow(i,x)>n) break;
            coins.push_back(pow(i,x));
        }
        for(int i=0;i<coins.size();i++){
            for(int j=0;j<=n;j++){
                second[j] = first[j];
                if(j>=coins[i]) second[j] = ((long long)second[j] + first[j-coins[i]])%((long long)1e9+7);
            } first = second;
        }
        return second[n];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends