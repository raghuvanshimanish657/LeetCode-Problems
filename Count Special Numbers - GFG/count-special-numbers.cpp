//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        // Code here
        int m=INT_MIN,cnt=0;
        for(int i:arr){
            m=max(i,m);
        }
        vector<int>seive(m+1,0);
        for(int i:arr){
            if(seive[i]<2){
                for(int j=i;j<=m;j+=i){
                    seive[j]+=1;
                }
            }
        }
        for(int i:arr){
            if(seive[i]>1)++cnt;
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends