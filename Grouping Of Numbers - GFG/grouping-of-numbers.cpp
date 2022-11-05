//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxGroupSize(int arr[], int n, int k) {
        // code here
        int rem[k];
        memset(rem, 0, sizeof(rem));
        for(int i=0; i<n; i++){
            rem[ arr[i]%k ]++;
        }

        int ans=0;
        int i=1, j=k-1;
       //pick max of (i, k-i)
        while(i<j){
            ans+= max(rem[i++], rem[j--]);
        }
        if(rem[0]!=0){
            ans++;
        }
        // if k is even pick the middle element only one time as
        //(k/2+k/2)%k=0;
        if((k&1)==0 and rem[k/2]) ans++;
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxGroupSize(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends